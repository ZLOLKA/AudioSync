#include "Settings.hpp"

#include "DebugTools/ASSERT.hpp"

#include <cassert>

namespace AudioSync {

const Settings* Settings::getSettings() NOEXCEPT_T {
  if (not Settings::settings.get()) {
    Settings::settings = std::unique_ptr<Settings>(new Settings());
  }
  return Settings::settings.get();
}

auto Settings::getStorageFileName() const NOEXCEPT_T  //
    -> const decltype(storageFileName)& {
  return settings->storageFileName;
}

auto Settings::getOtherDirectoriesPaths() const NOEXCEPT_T  //
    -> const decltype(otherDirectoriesPaths)& {
  return settings->otherDirectoriesPaths;
}

auto Settings::getStreamingServicesNames() const NOEXCEPT_T  //
    -> const decltype(streamingServicesNames)& {
  return settings->streamingServicesNames;
}

auto Settings::getPath2RootDir() const NOEXCEPT_T  //
    -> const decltype(path2RootDir)& {
  return path2RootDir;
}

template<auto Settings::*mem1, auto Settings::*mem2, auto Settings::*... mems>
void Settings::parse() NOEXCEPT_T {
  parse<mem1>();
  parse<mem2>();
  (parse<mems>(), ...);
}

template<>
void Settings::parse<&Settings::storageFileName>() NOEXCEPT_T {
  ASSERT(false, "TODO: Not implemented");
}

template<>
void Settings::parse<&Settings::otherDirectoriesPaths>() NOEXCEPT_T {
  ASSERT(false, "TODO: Not implemented");
}

template<>
void Settings::parse<&Settings::streamingServicesNames>() NOEXCEPT_T {
  ASSERT(false, "TODO: Not implemented");
}

template<>
void Settings::parse<&Settings::path2RootDir>() NOEXCEPT_T {
  ASSERT(false, "TODO: Not implemented");
}

Settings::Settings() NOEXCEPT_T {
  parse<
      &Settings::storageFileName,
      &Settings::otherDirectoriesPaths,
      &Settings::streamingServicesNames,
      &Settings::path2RootDir>();
}

}  // namespace AudioSync
