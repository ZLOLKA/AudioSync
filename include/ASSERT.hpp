#pragma once

#ifndef NDEBUG
#   include <cassert>
#   define ASSERT(cond, msg) assert((msg) && (cond))
#else
#   include <cstdlib>
#   define ASSERT(cond, msg) std::abort()
#endif

