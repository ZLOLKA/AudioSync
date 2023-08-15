#pragma once

#include "AudioLibraryInfo.hpp"
#include "DebugTools/NOEXCEPT.hpp"
#include "Target.hpp"

#include <memory>
#include <string>
#include <vector>

namespace std::filesystem {
class path;
}  // namespace std::filesystem

namespace AudioSync {

class OtherDirectory : public Target {
private:
  AudioLibraryInfo info;

public:
  static std::vector<std::unique_ptr<Target>> getOtherDirectories() NOEXCEPT_T;

public:
  virtual ~OtherDirectory() = default;
  const AudioLibraryInfo& getInfo() const NOEXCEPT_T override;
  std::string getName() const NOEXCEPT_T override;

public:
  OtherDirectory(const std::filesystem::path& path) NOEXCEPT_T;
  OtherDirectory(AudioLibraryInfo&& info) NOEXCEPT_T;
};

}  // namespace AudioSync
