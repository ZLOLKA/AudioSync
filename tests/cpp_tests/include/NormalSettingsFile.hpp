#pragma once

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class NormalSettingsFile : public SettingsFileFixture {
public:
  NormalSettingsFile();
  ~NormalSettingsFile() override;
};

}  // namespace AudioSync::Tests
