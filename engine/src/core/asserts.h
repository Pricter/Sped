#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define SASSERTIONS_ENABLED

#ifdef SASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

SAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define SASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define SASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define SASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define SASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define SASSERT(expr)               // Does nothing at all
#define SASSERT_MSG(expr, message)  // Does nothing at all
#define SASSERT_DEBUG(expr)         // Does nothing at all
#endif