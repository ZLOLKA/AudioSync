#pragma once

#include <cstdint>
#include <set>

namespace AudioSync {

class BaseAudioInfo;

namespace Diff {
    enum class Mode: std::uint8_t {
        Add
        , Delete
        , Modify
    };

    class Type: public std::set<std::pair<Type, BaseAudioInfo*>> {

    };
}

}

