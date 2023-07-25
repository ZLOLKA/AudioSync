#pragma once

#include <filesystem>
#include <string>

namespace YAML {
template<class T>
struct convert;

class Emitter;
class Node;
}  // namespace YAML

namespace AudioSync {

class BaseAudioInfo {
public:
  std::string author;
  std::string track_name;
  std::string album;

public:
  std::string serialize() const;

  static BaseAudioInfo deserialize(const YAML::Node& serializedData);
};

}  // namespace AudioSync

namespace YAML {

YAML::Emitter& operator<<(YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info);

template<>
struct convert<AudioSync::BaseAudioInfo> {
  static bool decode(const Node& node, AudioSync::BaseAudioInfo& childs);
};

}  // namespace YAML
