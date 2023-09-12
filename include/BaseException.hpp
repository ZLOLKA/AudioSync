#pragma once

#include "DebugTools/NOEXCEPT.hpp"

namespace AudioSync {

class BaseException {
public:
  constexpr static bool is_exception = true;

  virtual ~BaseException() NOEXCEPT_T;

  virtual const char* what() const NOEXCEPT_T;
};

}  // namespace AudioSync
