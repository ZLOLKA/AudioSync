#pragma once

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
  static const Settings* getSettings();

public:
  auto getStorageFileName() const  //
      -> const decltype(storageFileName)&;
  auto getOtherDirectoriesPaths() const  //
      -> const decltype(otherDirectoriesPaths)&;
  auto getStreamingServicesNames() const  //
      -> const decltype(streamingServicesNames)&;
  auto getPath2RootDir() const  //
      -> const decltype(path2RootDir)&;

private:
  Settings();

  template<auto Settings::*mem1, auto Settings::*mem2, auto Settings::*... mems>
  void parse();

  template<auto Settings::*mem>
  void parse() = delete;
};

}  // namespace AudioSync
