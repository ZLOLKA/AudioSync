#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class NormalSettingsFile : public SettingsFileFixture {
public:
  NormalSettingsFile() NOEXCEPT_T;
  ~NormalSettingsFile() NOEXCEPT_T override;
};

}  // namespace AudioSync::Tests
