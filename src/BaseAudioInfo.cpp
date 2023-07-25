#include "BaseAudioInfo.hpp"

#include "yaml-cpp/emitter.h"
#include "yaml-cpp/emittermanip.h"
#include "yaml-cpp/yaml.h"

namespace AudioSync {

std::string BaseAudioInfo::serialize() const {
  YAML::Emitter yaml;
  yaml << *this;
  return yaml.c_str();
}

BaseAudioInfo BaseAudioInfo::deserialize(const YAML::Node& serializedData) {
  BaseAudioInfo res;

  res.author = serializedData["author"].as<std::string>();
  res.track_name = serializedData["track_name"].as<std::string>();
  res.album = serializedData["album"].as<std::string>();

  return res;
}

}  // namespace AudioSync

namespace YAML {

YAML::Emitter& operator<<(YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info) {
  yaml << YAML::BeginMap;
  yaml << YAML::Key << "author" << YAML::Value << info.author;
  yaml << YAML::Key << "track_name" << YAML::Value << info.track_name;
  yaml << YAML::Key << "album" << YAML::Value << info.album;
  yaml << YAML::EndMap;
  return yaml;
}

bool convert<AudioSync::BaseAudioInfo>::decode(
    const Node& node,
    AudioSync::BaseAudioInfo& info
) {
  if (not node.IsMap())
    return false;

  info = AudioSync::BaseAudioInfo::deserialize(node);

  return true;
}

}  // namespace YAML
