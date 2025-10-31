#pragma once

#define ENGINE_API
#define IMGUI_OPENGL_VERSION "#version 430"

#ifdef GE_DEBUG
#ifdef GE_PLATFORM_WINDOWS
#define GE_DEBUGBREAK() __debugbreak()
#else
#define GE_DEBUGBREAK() raise(SIGTRAP)
#endif
#define GE_ENABLE_ASSERTS
#endif

#ifdef GE_ENABLE_ASSERTS
#define GE_ASSERT(x, ...)                                   \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            GE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                 \
        }                                                   \
    }
#define GE_CORE_ASSERT(x, ...)                                   \
    {                                                            \
        if (!(x))                                                \
        {                                                        \
            GE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                      \
        }                                                        \
    }
#else
#define GE_ASSERT(x, ...)
#define GE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GE_BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

#include "gepch.h"
