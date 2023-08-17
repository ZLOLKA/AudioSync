#include "Settings.hpp"

#include <gtest/gtest.h>

namespace AudioSync {

TEST(SettingsTests, SingletonTest) {
  auto settings0 = Settings::getSettings();
  auto settings1 = Settings::getSettings();
  EXPECT_TRUE(settings0 == settings1);
}

}  // namespace AudioSync
