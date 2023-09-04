#include "NormalSettingsFile.hpp"

#include "DebugTools/ASSERT.hpp"
#include "DebugTools/NOEXCEPT.hpp"
#include "Settings.hpp"

#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <fstream>

namespace AudioSync::Tests {

NormalSettingsFile::NormalSettingsFile() NOEXCEPT_T {
  std::ofstream settingsFile(::AudioSync::Settings::fileName);
  ASSERT(settingsFile.is_open(), "SettingsFile has not been created");

  ::YAML::Emitter yaml(settingsFile);
  yaml << ::YAML::BeginMap;
  yaml << ::YAML::Key << "storageFileName" << ::YAML::Value << "AudioSync.yaml";
  yaml << ::YAML::Key << "path2RootDir" << ::YAML::Value << "./Music";
  yaml << ::YAML::Key << "path2OtherDirectories" << ::YAML::Value
       << ::YAML::BeginSeq << ::YAML::EndSeq;
  yaml << ::YAML::Key << "streamingServicesNames" << ::YAML::Value
       << ::YAML::BeginSeq << ::YAML::EndSeq;
  yaml << ::YAML::EndMap;
}

NormalSettingsFile::~NormalSettingsFile() NOEXCEPT_T {
  try {
    std::filesystem::remove(::AudioSync::Settings::fileName);
  } catch (std::filesystem::filesystem_error& e) {
    ASSERT(false, "SettingsFile has not been deleted");
  }
}

}  // namespace AudioSync::Tests
