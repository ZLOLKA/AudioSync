#pragma once

#include "DebugTools/NOEXCEPT.hpp"
#include "Target.hpp"

#include <memory>
#include <string>
#include <vector>

namespace AudioSync {

class StreamingAPI : public Target {
private:
  const std::string name;

public:
  virtual ~StreamingAPI() = default;
  std::string getName() const NOEXCEPT_T override;

public:
  static std::vector<std::unique_ptr<Target>> getStreamingServices() NOEXCEPT_T;
  static std::unique_ptr<StreamingAPI> getStreamingServiceByName(
      const std::string& name
  ) NOEXCEPT_T;

private:
  StreamingAPI() NOEXCEPT_T = default;
};

}  // namespace AudioSync
