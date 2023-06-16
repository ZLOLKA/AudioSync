#include "BaseFunctions.hpp"
#include "StreamingAPI.hpp"
#include "Tools.hpp"

namespace AudioSync {

void syncWithStreamingServices(AudioLibraryInfo& ourInfo) {
    baseSyncWith<
        StreamingAPI
        , &StreamingAPI::getStreamingServices
        , &StreamingAPI::getInfo
        , &StreamingAPI::name
    >(ourInfo);
}

}

