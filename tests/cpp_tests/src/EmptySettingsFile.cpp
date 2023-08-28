#include "EmptySettingsFile.hpp"

#include "DebugTools/ASSERT.hpp"
#include "Settings.hpp"

#include <filesystem>
#include <fstream>

namespace AudioSync::Tests {

EmptySettingsFile::EmptySettingsFile() {
  std::ofstream settingsFile(::AudioSync::Settings::fileName);
  ASSERT(settingsFile.is_open(), "SettingsFile has not been created");
}

EmptySettingsFile::~EmptySettingsFile() {
  try {
    std::filesystem::remove(::AudioSync::Settings::fileName);
  } catch (std::filesystem::filesystem_error& e) {
    ASSERT(false, "SettingsFile has not been deleted");
  }
}

}  // namespace AudioSync::Tests
