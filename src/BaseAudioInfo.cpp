#include "yaml-cpp/emitter.h"
#include "yaml-cpp/emittermanip.h"
#include "yaml-cpp/yaml.h"

#include "BaseAudioInfo.hpp"

namespace AudioSync {

std::string BaseAudioInfo::serialize() const {
    YAML::Emitter yaml;
    yaml << *this;
    return yaml.c_str();
}

}

namespace YAML {

YAML::Emitter& operator<< (
    YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info
) {
    yaml << YAML::BeginMap
        << YAML::Key << "author" << YAML::Value << info.author
        << YAML::Key << "track_name" << YAML::Value << info.track_name
        << YAML::Key << "album" << YAML::Value << info.album
    ;
    yaml << YAML::EndMap;
    return yaml;
}

}

