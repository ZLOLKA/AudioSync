#include <cassert>

#include "Settings.hpp"

namespace AudioSync {

auto Settings::getStorageFileName() const -> const decltype(storageFileName)& {
    return storageFileName;
}

template<auto Settings::* mem1, auto Settings::* mem2, auto Settings::* ... mems>
void Settings::parse() {
    parse<mem1>();
    parse<mem2>();
    (parse<mems>(), ...);
}

template<>
void Settings::parse<&Settings::storageFileName>() {
    assert(!"TODO: Not implemented");
}

Settings::Settings() {
    parse<
        &Settings::storageFileName
    >();
}

}
