#pragma once

#include "AudioLibraryInfo.hpp"

#include <string>

namespace AudioSync {

class Target {
public:
  virtual const AudioLibraryInfo& getInfo() const NOEXCEPT_T = 0;
  virtual std::string getName() const NOEXCEPT_T = 0;

  virtual ~Target() = default;
};

}  // namespace AudioSync
