#pragma once

#include <filesystem>
#include <string>

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

