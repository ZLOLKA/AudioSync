#pragma once

#include "BaseAudioInfo.hpp"
#include "DebugTools/ASSERT.hpp"
#include "DebugTools/NOEXCEPT.hpp"
#include "Diff.hpp"

#include <memory>
#include <set>
#include <string>
#include <variant>

namespace YAML {
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

  auto getChilds() const THROW_NEXT(Exceptions<AssertException>)  //
      -> const ContainerType&;

  auto getBaseAudioInfo() const THROW_NEXT(Exceptions<AssertException>)  //
      -> const BaseAudioInfo&;

private:
  void writeInfoInStorageFile(const std::filesystem::path& path2StorageFile
  ) const NOEXCEPT_T;
};

}  // namespace AudioSync
