#include "SettingsFileFixture.hpp"

#include "Settings.hpp"

namespace AudioSync::Tests {

SettingsFileFixture::~SettingsFileFixture() NOEXCEPT_T {
}

void SettingsFileFixture::singletonTest() NOEXCEPT_T {
  auto settings0 = ::AudioSync::Settings::getSettings();
  auto settings1 = ::AudioSync::Settings::getSettings();
  EXPECT_TRUE(settings0 == settings1);
}

}  // namespace AudioSync::Tests
