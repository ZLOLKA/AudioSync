#include "third-party/yaml-cpp/convert.hpp"

#include "yaml-cpp/yaml.h"

namespace YAML {

bool convert<AudioSync::BaseAudioInfo>::decode(
    const Node& node,
    AudioSync::BaseAudioInfo& info
) {
  if (not node.IsMap())
    return false;

  info = AudioSync::BaseAudioInfo::deserialize(node);

  return true;
}

bool convert<AudioSync::AudioLibraryInfo::ContainerType>::decode(
    const Node& node,
    AudioSync::AudioLibraryInfo::ContainerType& childs
) {
  if (not node.IsSequence())
    return false;

  for (auto sub_node : node) {
    if (not node.IsMap())
      return false;

    auto audio_library = AudioSync::AudioLibraryInfo::deserialize(sub_node);
    childs.emplace(
        std::make_unique<AudioSync::AudioLibraryInfo>(std::move(audio_library))
    );
  }

  return true;
}

}  // namespace YAML
