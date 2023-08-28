#pragma once

#include <gtest/gtest.h>

namespace AudioSync::Tests {

class SettingsFileFixture : public ::testing::Test {
public:
  virtual ~SettingsFileFixture() = 0;

public:
  void singletonTest();
};

}  // namespace AudioSync::Tests
