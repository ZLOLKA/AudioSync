#pragma once

#include "AudioLibraryInfo.hpp"

#include <memory>
#include <string>
#include <vector>

namespace std::filesystem {
class path;
}  // namespace std::filesystem

namespace AudioSync {

class OtherDirectory {
private:
  AudioLibraryInfo info;

public:
  static std::vector<std::unique_ptr<OtherDirectory>> getOtherDirectories();

public:
  OtherDirectory(const std::filesystem::path& path);
  OtherDirectory(AudioLibraryInfo&& info);

  auto getInfo()  //
      -> decltype(info)&;
  auto getInfo() const  //
      -> const decltype(info)&;

  auto getName() const  //
      -> std::string;
};

}  // namespace AudioSync
