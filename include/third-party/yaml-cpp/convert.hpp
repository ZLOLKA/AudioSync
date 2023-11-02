#pragma once

#include "AudioLibraryInfo.hpp"
#include "BaseAudioInfo.hpp"

namespace YAML {

template<class T>
struct convert;

class Node;

template<>
struct convert<AudioSync::BaseAudioInfo> {
  static bool decode(const Node& node, AudioSync::BaseAudioInfo& childs);
};

template<>
struct convert<AudioSync::AudioLibraryInfo::ContainerType> {
  static bool decode(
      const Node& node,
      AudioSync::AudioLibraryInfo::ContainerType& childs
  );
};

}  // namespace YAML
