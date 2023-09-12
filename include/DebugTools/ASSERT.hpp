#pragma once

#include "BaseException.hpp"

#include <string>

namespace AudioSync {

class AssertException : public ::AudioSync::BaseException {
private:
  std::string what_msg;

public:
  explicit AssertException(const std::string& what_msg) NOEXCEPT_T;

  const char* what() const NOEXCEPT_T override;
};

}  // namespace AudioSync

#ifndef NDEBUG
  #include <cassert>
  #if USE_ASSERT_AS_THROW
    #define ASSERT(cond, msg) \
      if (not (cond)) \
      throw ::AudioSync::AssertException( \
          std::string("\nASSERT from AudioSync: " __FILE__ " ") \
          + std::to_string(__LINE__) + ":" + "\n(" + #cond \
          + ") is false: " + (msg) \
      )
  #else
    #define ASSERT(cond, msg) assert((msg) && (cond))
  #endif
#else
  #include <cstdlib>
  #define ASSERT(cond, msg) std::abort()
#endif

#if not defined(NDEBUG) and USE_ASSERT_AS_THROW
  #define ASSERT_AS_THROW_BEGIN try
  #define ASSERT_AS_THROW_END \
    catch (::AudioSync::AssertException e) { \
      assert(e.what()); \
    }
#else
  #define ASSERT_AS_THROW_BEGIN
  #define ASSERT_AS_THROW_END
#endif
