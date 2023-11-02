#include "third-party/yaml-cpp/EmitterOperatorLShift.hpp"

#include "AudioLibraryInfo.hpp"
#include "BaseAudioInfo.hpp"

#include "yaml-cpp/yaml.h"

namespace YAML {

YAML::Emitter& operator<<(YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info) {
  yaml << YAML::BeginMap;
  yaml << YAML::Key << "author" << YAML::Value << info.author;
  yaml << YAML::Key << "track_name" << YAML::Value << info.track_name;
  yaml << YAML::Key << "album" << YAML::Value << info.album;
  yaml << YAML::EndMap;
  return yaml;
}

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const std::unique_ptr<AudioSync::AudioLibraryInfo>& info_ptr
) {
  yaml << *(info_ptr.get());
  return yaml;
}

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const AudioSync::AudioLibraryInfo& info
) {
  const bool is_dir = info.isDir();
  yaml << YAML::BeginMap;
  yaml << YAML::Key << "file_name" << YAML::Value << info.getFileName().string();
  yaml << YAML::Key << "isDir" << YAML::Value << is_dir;
  yaml << YAML::Key << "storage" << YAML::Value;
  if (is_dir) {
    yaml << info.getChilds();
  } else {
    yaml << info.getBaseAudioInfo();
  }
  yaml << YAML::EndMap;

  return yaml;
}

}  // namespace YAML
