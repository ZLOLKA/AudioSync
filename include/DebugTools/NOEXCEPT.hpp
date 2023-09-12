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

namespace AudioSync {

template<class Exception, class... Exceptions>
struct IsException {
private:
  constexpr static bool allTypesIsException =
      (Exception::is_exception && ... && Exceptions::is_exception);
  static_assert(allTypesIsException, "All types must be Exceptions");

public:
  constexpr static bool value = allTypesIsException;
};

template<class Type, class... Types>
constexpr bool Exceptions = IsException<Type, Types...>::value;

}  // namespace AudioSync

#define THROW_NEXT(exp) NOEXCEPT(not (exp))
