#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class WithoutSettingsFile : public SettingsFileFixture {
public:
  ~WithoutSettingsFile() NOEXCEPT_T override;
};

}  // namespace AudioSync::Tests
