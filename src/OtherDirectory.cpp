#include "OtherDirectory.hpp"

#include "yaml-cpp/yaml.h"

#include "Settings.hpp"

namespace AudioSync {

std::vector<std::unique_ptr<OtherDirectory>> OtherDirectory::getOtherDirectories() {
    const auto* settings = Settings::getSettings();
    const auto storageFileName = settings->getStorageFileName();
    std::vector<std::unique_ptr<OtherDirectory>> res;
    for (auto otherDirectoryPath: settings->getOtherDirectoriesPaths()) {
        const auto otherDirectoryInfoPath = otherDirectoryPath/storageFileName;
        res.emplace_back(std::make_unique<OtherDirectory>(otherDirectoryInfoPath));
    }
    return res;
}

OtherDirectory::OtherDirectory(const std::filesystem::path& path)
: OtherDirectory(AudioLibraryInfo::deserialize(YAML::LoadFile(path.string())))
{
}

auto OtherDirectory::getInfo() -> decltype(OtherDirectory::info)& {
    return info;
}
auto OtherDirectory::getInfo() const -> const decltype(OtherDirectory::info)& {
    return info;
}

std::string OtherDirectory::getName() const {
    return getInfo().getFileName().string();
}

}

