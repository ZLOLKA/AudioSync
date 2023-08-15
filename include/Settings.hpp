#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include <filesystem>
#include <memory>
#include <vector>

namespace AudioSync {

class Settings {  // Singleton by "settings" field
private:
  std::filesystem::path storageFileName;
  std::filesystem::path path2RootDir;
  std::vector<std::filesystem::path> otherDirectoriesPaths;
  std::vector<std::string> streamingServicesNames;

private:
  static inline std::unique_ptr<Settings> settings = nullptr;

public:
  static inline const std::filesystem::path fileName = "settings.yaml";

public:
  static const Settings* getSettings() NOEXCEPT_T;

public:
  auto getStorageFileName() const NOEXCEPT_T  //
      -> const decltype(storageFileName)&;
  auto getOtherDirectoriesPaths() const NOEXCEPT_T  //
      -> const decltype(otherDirectoriesPaths)&;
  auto getStreamingServicesNames() const NOEXCEPT_T  //
      -> const decltype(streamingServicesNames)&;
  auto getPath2RootDir() const NOEXCEPT_T  //
      -> const decltype(path2RootDir)&;

private:
  Settings() NOEXCEPT_T;

  template<auto Settings::*mem1, auto Settings::*mem2, auto Settings::*... mems>
  void parse() NOEXCEPT_T;

  template<auto Settings::*mem>
  void parse() NOEXCEPT_T = delete;
};

}  // namespace AudioSync
