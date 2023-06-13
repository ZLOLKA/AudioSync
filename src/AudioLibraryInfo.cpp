#include "AudioLibraryInfo.hpp"

namespace AudioSync {

bool AudioLibraryInfo::isDir() const {
    return childs.size() != 0; 
}

const decltype(AudioLibraryInfo::file_name)& AudioLibraryInfo::getFileName() const {
    return isDir() ? file_name : data.file_name;
}

const decltype(AudioLibraryInfo::childs)& AudioLibraryInfo::getChilds() const {
    return childs;
}

}

