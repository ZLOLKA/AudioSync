#pragma once

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
  std::string getName() const override;

public:
  static std::vector<std::unique_ptr<Target>> getStreamingServices();
  static std::unique_ptr<StreamingAPI> getStreamingServiceByName(
      const std::string& name
  );

private:
  StreamingAPI() = default;
};

}  // namespace AudioSync
