#pragma once

#include "AudioLibraryInfo.hpp"

#include <memory>
#include <string>
#include <type_traits>
#include <vector>

namespace AudioSync {

class StreamingAPI {
private:
  const std::string name;

public:
  virtual const AudioLibraryInfo& getInfo() const = 0;

  virtual ~StreamingAPI() = default;

public:
  static std::vector<std::unique_ptr<StreamingAPI>> getStreamingServices();

public:
  auto getName() const  //
      -> std::remove_const_t<std::remove_reference_t<decltype(name)>>;

private:
  StreamingAPI() = default;
};

}  // namespace AudioSync
