#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include <memory>
#include <vector>

namespace AudioSync {

class AudioLibraryInfo;
class Target;

void baseSyncWith(
    AudioLibraryInfo& ourInfo,
    std::vector<std::unique_ptr<Target>> sources
) NOEXCEPT_T;

}  // namespace AudioSync
