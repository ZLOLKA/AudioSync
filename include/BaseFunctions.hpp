#pragma once

#include "DebugTools/NOEXCEPT.hpp"

namespace AudioSync {

class AudioLibraryInfo;

void syncWithStreamingServices(AudioLibraryInfo& ourInfo) NOEXCEPT_T;

void syncWithLocalDirectories(AudioLibraryInfo& ourInfo) NOEXCEPT_T;

}  // namespace AudioSync
