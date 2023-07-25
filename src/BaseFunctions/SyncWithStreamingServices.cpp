#include "BaseFunctions.hpp"
#include "StreamingAPI.hpp"
#include "Tools.hpp"

namespace AudioSync {

void syncWithStreamingServices(AudioLibraryInfo& ourInfo) {
  baseSyncWith(ourInfo, StreamingAPI::getStreamingServices());
}

}  // namespace AudioSync
