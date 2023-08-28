#pragma once

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class WithoutSettingsFile : public SettingsFileFixture {
public:
  ~WithoutSettingsFile() override;
};

}  // namespace AudioSync::Tests
