#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class EmptySettingsFile : public SettingsFileFixture {
public:
  EmptySettingsFile() NOEXCEPT_T;
  ~EmptySettingsFile() NOEXCEPT_T override;
};

}  // namespace AudioSync::Tests
