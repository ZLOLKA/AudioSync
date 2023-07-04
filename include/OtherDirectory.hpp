#pragma once

#include <memory>
#include <string>
#include <vector>

#include "AudioLibraryInfo.hpp"

namespace std::filesystem {
class path;
}

namespace AudioSync {

class OtherDirectory {
private:
    AudioLibraryInfo info;

public:
    static std::vector<std::unique_ptr<OtherDirectory>> getOtherDirectories();

public:
    OtherDirectory(const std::filesystem::path& path);
    OtherDirectory(AudioLibraryInfo&& info);

    auto getInfo() -> decltype(info)&;
    auto getInfo() const -> const decltype(info)&;

    std::string getName() const;
};

}

