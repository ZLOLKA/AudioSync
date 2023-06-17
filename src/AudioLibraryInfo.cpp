#include <cassert>
#include <fstream>

#include "yaml-cpp/yaml.h"

#include "AudioLibraryInfo.hpp"
#include "Settings.hpp"

namespace AudioSync {

AudioLibraryInfo::~AudioLibraryInfo() {
    if (isDir()) {
        file_name.~decltype(file_name)();
    } 
    else {
        data.~BaseAudioInfo();
    }
    childs.~decltype(childs)();
}

bool AudioLibraryInfo::isDir() const {
    return childs.size() != 0; 
}

const decltype(AudioLibraryInfo::file_name)& AudioLibraryInfo::getFileName() const {
    return isDir() ? file_name : data.file_name;
}

const decltype(AudioLibraryInfo::childs)& AudioLibraryInfo::getChilds() const {
    return childs;
}

AudioLibraryInfo AudioLibraryInfo::getOurAudioLibraryInfo() {
    const auto settings = Settings::getSettings();
    const auto storageFileName = settings->getStorageFileName();

    const auto storageFile = YAML::LoadFile(storageFileName.string());
    return deserialize(storageFile);
}

}

