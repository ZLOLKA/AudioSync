#pragma once

#include <memory>
#include <set>
#include <string>
#include <variant>

#include "BaseAudioInfo.hpp"
#include "Diff.hpp"

namespace YAML {
    class Node;
}

namespace AudioSync {

class AudioLibraryInfo { // Tree-like structure
public:
    using ContainerType = std::set<std::unique_ptr<AudioLibraryInfo>>;

private:
    std::filesystem::path file_name;
    std::variant<ContainerType, BaseAudioInfo> storage;

public:
    static AudioLibraryInfo getOurAudioLibraryInfo();

    static AudioLibraryInfo deserialize(const YAML::Node& serializedData);

public:

    Diff::Type getDiffWith(const AudioLibraryInfo& other) const;

    std::string serialize() const;

    const decltype(file_name)& getFileName() const;

    bool isDir() const;

    const ContainerType& getChilds() const;

    const BaseAudioInfo& getBaseAudioInfo() const;
};

}

