#pragma once

#include "AudioLibraryInfo.hpp"
#include "Target.hpp"

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

namespace AudioSync {

class StreamingAPI : public Target {
private:
  const std::string name;

public:
  virtual ~StreamingAPI() = default;
  std::string getName() const override;

public:
  static std::vector<std::unique_ptr<Target>> getStreamingServices();

private:
  StreamingAPI() = default;
};

}  // namespace AudioSync
