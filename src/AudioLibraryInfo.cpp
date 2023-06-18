#include <fstream>
#include <type_traits>

#include "yaml-cpp/yaml.h"

#include "ASSERT.hpp"
#include "AudioLibraryInfo.hpp"
#include "Settings.hpp"

namespace AudioSync {

AudioLibraryInfo::AudioLibraryInfo(
    const decltype(file_name)& file_name
    , AudioLibraryInfo::VariantType&& storage
)
: file_name(file_name)
, storage(std::move(storage))
{
}

bool AudioLibraryInfo::isDir() const {
    return std::holds_alternative<AudioLibraryInfo::ContainerType>(storage);
}

const decltype(AudioLibraryInfo::file_name)& AudioLibraryInfo::getFileName() const {
    return file_name;
}

const AudioLibraryInfo::ContainerType& AudioLibraryInfo::getChilds() const {
    ASSERT(isDir(), "Get childs from BaseAudioInfo variant");
    return std::get<AudioLibraryInfo::ContainerType>(storage);
}

const BaseAudioInfo& AudioLibraryInfo::getBaseAudioInfo() const {
    ASSERT(not isDir(), "Get BaseAudioInfo from directory variant");
    return std::get<BaseAudioInfo>(storage);
}

AudioLibraryInfo AudioLibraryInfo::getOurAudioLibraryInfo() {
    const auto settings = Settings::getSettings();
    const auto storageFileName = settings->getStorageFileName();

    const auto storageFile = YAML::LoadFile(storageFileName.string());
    return deserialize(storageFile);
}

std::string AudioLibraryInfo::serialize() const {
    YAML::Emitter yaml;
    yaml << *this;
    return yaml.c_str();
}

}

namespace YAML {

YAML::Emitter& operator<< (
    YAML::Emitter& yaml
    , const std::unique_ptr<AudioSync::AudioLibraryInfo>& info_ptr
) {
    yaml << *(info_ptr.get());
    return yaml;
}

YAML::Emitter& operator<< (
    YAML::Emitter& yaml, const AudioSync::AudioLibraryInfo& info
) {
    const bool is_dir = info.isDir();
    yaml << YAML::BeginMap
        << YAML::Key << "file_name" << YAML::Value << info.getFileName().string()
        << YAML::Key << "isDir" << YAML::Value << is_dir
        << YAML::Key << "storage" << YAML::Value
    ;
    if (is_dir) {
        yaml << info.getChilds();
    }
    else {
        yaml << info.getBaseAudioInfo();
    }
    yaml << YAML::EndMap;

    return yaml;
}

}

