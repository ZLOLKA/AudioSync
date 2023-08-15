#pragma once

/* The -fno-exceptions compilation option is unacceptable because this option
 * forbids the use of try/catch, and the libraries we depend on use throws to
 * communicate with the code calling them
 * */

#ifndef NOEXCEPT_MODE
  #error "NOEXCEPT_MODE compile option not setted"
#endif

#if NOEXCEPT_MODE > 0
  #define NOEXCEPT(exp) noexcept(true)
#elif NOEXCEPT_MODE == 0
  #define NOEXCEPT(exp) noexcept(exp)
#elif NOEXCEPT_MODE < 0
  #define NOEXCEPT(exp) noexcept(false)
#endif

#define NOEXCEPT_T NOEXCEPT(true)
