#pragma once

#include <filesystem>
#include <memory>

namespace AudioSync {

class Settings {
private:
    std::filesystem::path storageFileName;

private:
    static std::unique_ptr<Settings> settings;

public:
    static inline const std::filesystem::path fileName = "settings.yaml";

public:
    static void loadSettings();

public:
    auto getStorageFileName() const -> const decltype(storageFileName)&;

private:
    Settings();

    template<auto Settings::* mem1, auto Settings::* mem2, auto Settings::* ... mems>
    void parse();

    template<auto Settings::* mem>
    void parse() = delete;
};

}

