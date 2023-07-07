#include "BaseFunctions.hpp"
#include "OtherDirectory.hpp"
#include "Tools.hpp"

namespace AudioSync {

void syncWithLocalDirectories(AudioLibraryInfo& ourInfo) {
    baseSyncWith<
        OtherDirectory
        , &OtherDirectory::getOtherDirectories
        , &OtherDirectory::getInfo
        , &OtherDirectory::getName
    >(ourInfo);
}

}

