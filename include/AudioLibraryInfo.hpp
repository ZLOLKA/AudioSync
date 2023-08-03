#pragma once

#include "BaseAudioInfo.hpp"
#include "Diff.hpp"

#include <memory>
#include <set>
#include <string>
#include <variant>

namespace YAML {
template<class T>
struct convert;

class Emitter;
class Node;
}  // namespace YAML

namespace AudioSync {

class AudioLibraryInfo {  // Tree-like structure
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
      const decltype(file_name)& file_name,
      VariantType&& storage
  );
  AudioLibraryInfo(AudioLibraryInfo&& other) = default;

  auto getDiffWith(const AudioLibraryInfo& other) const  //
      -> Diff::Type;

  std::string serialize() const;

  auto getFileName() const  //
      -> const decltype(file_name)&;

  bool isDir() const;

  auto getChilds() const  //
      -> const ContainerType&;

  auto getBaseAudioInfo() const  //
      -> const BaseAudioInfo&;
};

}  // namespace AudioSync

namespace YAML {

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const std::unique_ptr<AudioSync::AudioLibraryInfo>& info_ptr
);

YAML::Emitter& operator<<(
    YAML::Emitter& yaml,
    const AudioSync::AudioLibraryInfo& info
);

template<>
struct convert<AudioSync::AudioLibraryInfo::ContainerType> {
  static bool decode(
      const Node& node,
      AudioSync::AudioLibraryInfo::ContainerType& childs
  );
};

}  // namespace YAML
