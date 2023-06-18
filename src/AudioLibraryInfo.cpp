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

}

