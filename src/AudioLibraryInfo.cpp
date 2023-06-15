#include <cassert>
#include <fstream>

#include "ASSERT.hpp"
#include "AudioLibraryInfo.hpp"
#include "Settings.hpp"

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

AudioLibraryInfo AudioLibraryInfo::getOurAudioLibraryInfo() {
    const auto settings = Settings::getSettings();
    const auto storageFileName = settings->getStorageFileName();

    std::filebuf fileBuf;
    if (not fileBuf.open(storageFileName, std::ios::in)) { // TODO: Rewrite as work in files
        ASSERT(false, "Storage file not open");
    }
    const auto fileSize = fileBuf.in_avail();
    std::string strFromFile(fileSize, '\0');
    const std::size_t countReadedChars = fileBuf.sgetn(
        const_cast<char *>(strFromFile.c_str())
        , fileSize
    );
    if (strFromFile.size() != countReadedChars) {
        ASSERT(false, "Storage file not readed");
    }

    return deserialize(strFromFile);
}

}

