#pragma once

#include "SettingsFileFixture.hpp"

namespace AudioSync::Tests {

class EmptySettingsFile : public SettingsFileFixture {
public:
  EmptySettingsFile();
  ~EmptySettingsFile() override;
};

}  // namespace AudioSync::Tests
