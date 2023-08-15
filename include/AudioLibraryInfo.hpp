#pragma once

#include "BaseAudioInfo.hpp"
#include "DebugTools/NOEXCEPT.hpp"
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
  static AudioLibraryInfo getOurAudioLibraryInfo() NOEXCEPT_T;

  static AudioLibraryInfo deserialize(const YAML::Node& serializedData
  ) NOEXCEPT_T;

  static AudioLibraryInfo createInfoFromRootDir(
      const std::filesystem::path& path2RootDir
  ) NOEXCEPT_T;

public:
  explicit AudioLibraryInfo(
      const decltype(file_name)& file_name,
      VariantType&& storage
  ) NOEXCEPT_T;
  AudioLibraryInfo(AudioLibraryInfo&& other) NOEXCEPT_T = default;

  auto getDiffWith(const AudioLibraryInfo& other) const NOEXCEPT_T  //
      -> Diff::Type;

  std::string serialize() const NOEXCEPT_T;

  auto getFileName() const NOEXCEPT_T  //
      -> const decltype(file_name)&;

  bool isDir() const NOEXCEPT_T;

  auto getChilds() const NOEXCEPT_T  //
      -> const ContainerType&;

  auto getBaseAudioInfo() const NOEXCEPT_T  //
      -> const BaseAudioInfo&;

private:
  void writeInfoInStorageFile(const std::filesystem::path& path2StorageFile
  ) const NOEXCEPT_T;
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
