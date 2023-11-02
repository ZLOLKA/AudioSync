#pragma once

#include "DebugTools/NOEXCEPT.hpp"

#include <filesystem>
#include <string>

namespace YAML {
class Node;
}  // namespace YAML

namespace AudioSync {

class BaseAudioInfo {
public:
  std::string author;
  std::string track_name;
  std::string album;

public:
  std::string serialize() const NOEXCEPT_T;

  static BaseAudioInfo deserialize(const YAML::Node& serializedData) NOEXCEPT_T;
};

}  // namespace AudioSync
