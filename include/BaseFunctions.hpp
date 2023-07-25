#pragma once

namespace AudioSync {

class AudioLibraryInfo;

void syncWithStreamingServices(AudioLibraryInfo& ourInfo);

void syncWithLocalDirectories(AudioLibraryInfo& ourInfo);

}  // namespace AudioSync
