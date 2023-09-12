#include "BaseException.hpp"

namespace AudioSync {

BaseException::~BaseException() NOEXCEPT_T = default;

const char* BaseException::what() const NOEXCEPT_T {
  return "Unknown exception from AudioSync";
}

}  // namespace AudioSync
