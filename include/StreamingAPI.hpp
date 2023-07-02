#pragma once

#include <memory>
#include <string>
#include <vector>

#include "AudioLibraryInfo.hpp"

namespace AudioSync {

class StreamingAPI {
private:
    const std::string name;

public:
    virtual AudioLibraryInfo getInfo() const = 0;

    virtual ~StreamingAPI() = default;

public:
    static std::vector<std::unique_ptr<StreamingAPI>> getStreamingServices();

public:
    std::string getName() const;

private:
    StreamingAPI() = default;
};

}

