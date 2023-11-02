#include "AudioLibraryInfo.hpp"

#include "Settings.hpp"
#include "third-party/yaml-cpp/EmitterOperatorLShift.hpp"
#include "third-party/yaml-cpp/convert.hpp"

#include "yaml-cpp/yaml.h"

#include <fstream>
#include <type_traits>

namespace AudioSync {

AudioLibraryInfo::AudioLibraryInfo(
    const decltype(file_name)& file_name,
    AudioLibraryInfo::VariantType&& storage
) NOEXCEPT_T
    : file_name(file_name)
    , storage(std::move(storage)) {
}

bool AudioLibraryInfo::isDir() const NOEXCEPT_T {
  return std::holds_alternative<AudioLibraryInfo::ContainerType>(storage);
}

auto AudioLibraryInfo::getFileName() const NOEXCEPT_T  //
    -> const decltype(AudioLibraryInfo::file_name)& {
  return file_name;
}

auto AudioLibraryInfo::getChilds(
) const THROW_NEXT(Exceptions<AssertException>)  //
    -> const AudioLibraryInfo::ContainerType& {
  ASSERT(isDir(), "Get childs from BaseAudioInfo variant");
  return std::get<AudioLibraryInfo::ContainerType>(storage);
}

auto AudioLibraryInfo::getBaseAudioInfo(
) const THROW_NEXT(Exceptions<AssertException>)  //
    -> const BaseAudioInfo& {
  ASSERT(not isDir(), "Get BaseAudioInfo from directory variant");
  return std::get<BaseAudioInfo>(storage);
}

auto AudioLibraryInfo::getOurAudioLibraryInfo() NOEXCEPT_T  //
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

std::string AudioLibraryInfo::serialize() const NOEXCEPT_T {
  YAML::Emitter yaml;
  yaml << *this;
  return yaml.c_str();
}

AudioLibraryInfo AudioLibraryInfo::deserialize(const YAML::Node& serializedData
) NOEXCEPT_T {
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
