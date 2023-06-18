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
    template<class T>
    using Container = std::set<T>;
    using ContainerType = Container<std::unique_ptr<AudioLibraryInfo>>;
    using VariantType = std::variant<ContainerType, BaseAudioInfo>;

private:
    std::filesystem::path file_name;
    VariantType storage;

public:
    static AudioLibraryInfo getOurAudioLibraryInfo();

    static AudioLibraryInfo deserialize(const YAML::Node& serializedData);

public:
    explicit AudioLibraryInfo(
        const decltype(file_name)& file_name, VariantType&& storage
    );

    Diff::Type getDiffWith(const AudioLibraryInfo& other) const;

    std::string serialize() const;

    const decltype(file_name)& getFileName() const;

    bool isDir() const;

    const ContainerType& getChilds() const;

    const BaseAudioInfo& getBaseAudioInfo() const;
};

}

