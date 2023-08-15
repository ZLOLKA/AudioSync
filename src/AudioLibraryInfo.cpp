#include "AudioLibraryInfo.hpp"

#include "ASSERT.hpp"
#include "Settings.hpp"

#include "yaml-cpp/yaml.h"

#include <fstream>
#include <type_traits>

namespace AudioSync {

AudioLibraryInfo::AudioLibraryInfo(
    const decltype(file_name)& file_name,
    AudioLibraryInfo::VariantType&& storage
)
    : file_name(file_name)
    , storage(std::move(storage)) {
}

bool AudioLibraryInfo::isDir() const {
  return std::holds_alternative<AudioLibraryInfo::ContainerType>(storage);
}

auto AudioLibraryInfo::getFileName() const  //
    -> const decltype(AudioLibraryInfo::file_name)& {
  return file_name;
}

auto AudioLibraryInfo::getChilds() const  //
    -> const AudioLibraryInfo::ContainerType& {
  ASSERT(isDir(), "Get childs from BaseAudioInfo variant");
  return std::get<AudioLibraryInfo::ContainerType>(storage);
}

auto AudioLibraryInfo::getBaseAudioInfo() const  //
    -> const BaseAudioInfo& {
  ASSERT(not isDir(), "Get BaseAudioInfo from directory variant");
  return std::get<BaseAudioInfo>(storage);
}

auto AudioLibraryInfo::getOurAudioLibraryInfo()  //
    -> AudioLibraryInfo {
  const auto settings = Settings::getSettings();
  const auto storageFileName = settings->getStorageFileName();

  try {
    const auto storageFile = YAML::LoadFile(storageFileName.string());
    return deserialize(storageFile);
  } catch (YAML::BadFile) {  // Generate in YAML::LoadFile(const std::string&)
    const auto path2RootDir = settings->getPath2RootDir();
    auto info = createInfoFromRootDir(path2RootDir);
    info.writeInfoInStorageFile(storageFileName);
    return info;
  }
}

std::string AudioLibraryInfo::serialize() const {
  YAML::Emitter yaml;
  yaml << *this;
  return yaml.c_str();
}

AudioLibraryInfo AudioLibraryInfo::deserialize(const YAML::Node& serializedData) {
  const auto file_name = serializedData["file_name"].as<std::string>();

  const auto isDir = serializedData["isDir"].as<bool>();
  AudioLibraryInfo::VariantType storage;
  const auto yaml_storage = serializedData["storage"];
  if (isDir) {
    auto childs = yaml_storage.as<AudioLibraryInfo::ContainerType>();
    storage = std::move(childs);
  } else {
    auto info = yaml_storage.as<BaseAudioInfo>();
    storage = std::move(info);
  }

  return AudioLibraryInfo { file_name, std::move(storage) };
}

}  // namespace AudioSync

namespace YAML {

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const std::unique_ptr<AudioSync::AudioLibraryInfo>& info_ptr
) {
  yaml << *(info_ptr.get());
  return yaml;
}

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const AudioSync::AudioLibraryInfo& info
) {
  const bool is_dir = info.isDir();
  yaml << YAML::BeginMap;
  yaml << YAML::Key << "file_name" << YAML::Value << info.getFileName().string();
  yaml << YAML::Key << "isDir" << YAML::Value << is_dir;
  yaml << YAML::Key << "storage" << YAML::Value;
  if (is_dir) {
    yaml << info.getChilds();
  } else {
    yaml << info.getBaseAudioInfo();
  }
  yaml << YAML::EndMap;

  return yaml;
}

bool convert<AudioSync::AudioLibraryInfo::ContainerType>::decode(
    const Node& node,
    AudioSync::AudioLibraryInfo::ContainerType& childs
) {
  if (not node.IsSequence())
    return false;

  for (auto sub_node : node) {
    if (not node.IsMap())
      return false;

    auto audio_library = AudioSync::AudioLibraryInfo::deserialize(sub_node);
    childs.emplace(
        std::make_unique<AudioSync::AudioLibraryInfo>(std::move(audio_library))
    );
  }

  return true;
}

}  // namespace YAML
