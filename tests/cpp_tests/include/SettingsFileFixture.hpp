#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include <gtest/gtest.h>

namespace AudioSync::Tests {

class SettingsFileFixture : public ::testing::Test {
public:
  virtual ~SettingsFileFixture() NOEXCEPT_T = 0;

public:
  void singletonTest() NOEXCEPT_T;
};

}  // namespace AudioSync::Tests
