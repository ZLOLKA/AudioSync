#include "OtherDirectory.hpp"

#include "Settings.hpp"

#include "yaml-cpp/yaml.h"

namespace AudioSync {

std::vector<std::unique_ptr<Target>> OtherDirectory::getOtherDirectories(
) NOEXCEPT_T {
  const auto* settings = Settings::getSettings();
  const auto storageFileName = settings->getStorageFileName();
  std::vector<std::unique_ptr<Target>> res;
  for (auto otherDirectoryPath : settings->getOtherDirectoriesPaths()) {
    const auto otherDirectoryInfoPath = otherDirectoryPath / storageFileName;
    res.emplace_back(std::make_unique<OtherDirectory>(otherDirectoryInfoPath));
  }
  return res;
}

OtherDirectory::OtherDirectory(const std::filesystem::path& path) NOEXCEPT_T
    : OtherDirectory(AudioLibraryInfo::deserialize(YAML::LoadFile(path.string()))) {
}

OtherDirectory::OtherDirectory(AudioLibraryInfo&& info
) NOEXCEPT_T : info(std::move(info)) {
}

const AudioLibraryInfo& OtherDirectory::getInfo() const NOEXCEPT_T {
  return info;
}

std::string OtherDirectory::getName() const NOEXCEPT_T {
  return getInfo().getFileName().string();
}

}  // namespace AudioSync
