#pragma once

#include "AudioLibraryInfo.hpp"
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
  static std::vector<std::unique_ptr<Target>> getOtherDirectories();

public:
  virtual ~OtherDirectory() = default;
  const AudioLibraryInfo& getInfo() const override;
  std::string getName() const override;

public:
  OtherDirectory(const std::filesystem::path& path);
  OtherDirectory(AudioLibraryInfo&& info);
};

}  // namespace AudioSync
