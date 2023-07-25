#include "BaseFunctions.hpp"
#include "OtherDirectory.hpp"
#include "Tools.hpp"

namespace AudioSync {

void syncWithLocalDirectories(AudioLibraryInfo& ourInfo) {
  baseSyncWith(ourInfo, OtherDirectory::getOtherDirectories());
}

}  // namespace AudioSync
