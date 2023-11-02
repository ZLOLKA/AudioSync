#include "BaseAudioInfo.hpp"

#include "third-party/yaml-cpp/EmitterOperatorLShift.hpp"
#include "third-party/yaml-cpp/convert.hpp"

#include "yaml-cpp/yaml.h"

namespace AudioSync {

std::string BaseAudioInfo::serialize() const NOEXCEPT_T {
  YAML::Emitter yaml;
  yaml << *this;
  return yaml.c_str();
}

BaseAudioInfo BaseAudioInfo::deserialize(const YAML::Node& serializedData
) NOEXCEPT_T {
  BaseAudioInfo res;

  res.author = serializedData["author"].as<std::string>();
  res.track_name = serializedData["track_name"].as<std::string>();
  res.album = serializedData["album"].as<std::string>();

  return res;
}

}  // namespace AudioSync
