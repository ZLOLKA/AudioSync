#pragma once

#include <memory>

namespace AudioSync {
class AudioLibraryInfo;
class BaseAudioInfo;
}  // namespace AudioSync

namespace YAML {

class Emitter;

YAML::Emitter& operator<<(YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info);

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const std::unique_ptr<AudioSync::AudioLibraryInfo>& info_ptr
);

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const AudioSync::AudioLibraryInfo& info
);

}  // namespace YAML
