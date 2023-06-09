#pragma once

#include <filesystem>
#include <memory>
#include <vector>

namespace AudioSync {

class Settings { // Singleton by "settings" field
private:
    std::filesystem::path storageFileName;
    std::vector<std::filesystem::path> otherDirectoriesPaths;

private:
    static std::unique_ptr<Settings> settings;

public:
    static inline const std::filesystem::path fileName = "settings.yaml";

public:
    static const Settings* getSettings();

public:
    auto getStorageFileName() const -> const decltype(storageFileName)&;
    auto getOtherDirectoriesPaths() const -> const decltype(otherDirectoriesPaths)&;

private:
    Settings();

    template<auto Settings::* mem1, auto Settings::* mem2, auto Settings::* ... mems>
    void parse();

    template<auto Settings::* mem>
    void parse() = delete;
};

}

