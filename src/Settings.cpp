#include "Settings.hpp"

#include "ASSERT.hpp"

#include <cassert>

namespace AudioSync {

const Settings* Settings::getSettings() {
  if (not Settings::settings) {
    Settings::settings = std::unique_ptr<Settings>(new Settings());
  }
  return Settings::settings.get();
}

auto Settings::getStorageFileName() const  //
    -> const decltype(storageFileName)& {
  return settings->storageFileName;
}

auto Settings::getOtherDirectoriesPaths() const  //
    -> const decltype(otherDirectoriesPaths)& {
  return settings->otherDirectoriesPaths;
}

template<auto Settings::*mem1, auto Settings::*mem2, auto Settings::*... mems>
void Settings::parse() {
  parse<mem1>();
  parse<mem2>();
  (parse<mems>(), ...);
}

template<>
void Settings::parse<&Settings::storageFileName>() {
  ASSERT(false, "TODO: Not implemented");
}

template<>
void Settings::parse<&Settings::otherDirectoriesPaths>() {
  ASSERT(false, "TODO: Not implemented");
}

Settings::Settings() {
  parse<&Settings::storageFileName, &Settings::otherDirectoriesPaths>();
}

}  // namespace AudioSync
