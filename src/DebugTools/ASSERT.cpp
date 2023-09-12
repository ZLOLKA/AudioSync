#include "DebugTools/ASSERT.hpp"

namespace AudioSync {

AssertException::AssertException(const std::string& what_msg
) NOEXCEPT_T : what_msg(what_msg) {};

const char* AssertException::what() const NOEXCEPT_T {
  return what_msg.c_str();
}

}  // namespace AudioSync
