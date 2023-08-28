#include "Settings.hpp"

#include "EmptySettingsFile.hpp"
#include "NormalSettingsFile.hpp"
#include "TestTools.hpp"
#include "WithoutSettingsFile.hpp"

namespace AudioSync::Tests {

TEST_FM(NormalSettingsFile, singletonTest)

TEST_FM(EmptySettingsFile, singletonTest)

TEST_FM(WithoutSettingsFile, singletonTest)

}  // namespace AudioSync::Tests
