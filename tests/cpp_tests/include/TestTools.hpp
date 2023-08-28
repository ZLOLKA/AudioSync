#pragma once

#include <gtest/gtest.h>

namespace AudioSync::Test {

// TEST FixtureMethod
#define TEST_FM(FixtureClass, testMethod) \
  TEST_F(FixtureClass, testMethod) { \
    FixtureClass::testMethod(); \
  }

}  // namespace AudioSync::Test
