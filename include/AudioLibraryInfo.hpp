#pragma once

#include <memory>
#include <set>
#include <string>

#include "BaseAudioInfo.hpp"
#include "Diff.hpp"

namespace YAML {
    class Node;
}

namespace AudioSync {

class AudioLibraryInfo { // Tree-like structure
private:
    std::set<std::unique_ptr<AudioLibraryInfo>> childs;
    union {
        decltype(BaseAudioInfo::file_name) file_name;
        BaseAudioInfo data;
    };

public:
    static AudioLibraryInfo getOurAudioLibraryInfo();

    static AudioLibraryInfo deserialize(const YAML::Node& serializedData);

public:
    ~AudioLibraryInfo();

    Diff::Type getDiffWith(const AudioLibraryInfo& other) const;

    std::string serialize() const;

    const decltype(file_name)& getFileName() const;

    bool isDir() const;

    const decltype(childs)& getChilds() const;
};

}

