#pragma once

#include <filesystem>
#include <string>

namespace YAML {
    class Emitter;
}

namespace AudioSync {

class BaseAudioInfo {
public:
	std::string author;
	std::string track_name;
	std::string album;

public:
    std::string serialize() const;

    static BaseAudioInfo deserialize(const std::string& serializedData);
};

}

namespace YAML {

YAML::Emitter& operator<< (
    YAML::Emitter& yaml, const AudioSync::BaseAudioInfo& info
);

}

