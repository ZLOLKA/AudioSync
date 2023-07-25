#include "OtherDirectory.hpp"

#include "Settings.hpp"

#include "yaml-cpp/yaml.h"

namespace AudioSync {

std::vector<std::unique_ptr<Target>> OtherDirectory::getOtherDirectories() {
  const auto* settings = Settings::getSettings();
  const auto storageFileName = settings->getStorageFileName();
  std::vector<std::unique_ptr<Target>> res;
  for (auto otherDirectoryPath : settings->getOtherDirectoriesPaths()) {
    const auto otherDirectoryInfoPath = otherDirectoryPath / storageFileName;
    res.emplace_back(std::make_unique<OtherDirectory>(otherDirectoryInfoPath));
  }
  return res;
}

OtherDirectory::OtherDirectory(const std::filesystem::path& path)
    : OtherDirectory(AudioLibraryInfo::deserialize(YAML::LoadFile(path.string()))) {
}

OtherDirectory::OtherDirectory(AudioLibraryInfo&& info)
    : info(std::move(info)) {
}

const AudioLibraryInfo& OtherDirectory::getInfo() const {
  return info;
}

std::string OtherDirectory::getName() const {
  return getInfo().getFileName().string();
}

}  // namespace AudioSync
