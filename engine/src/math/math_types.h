#pragma once

#include "defines.h"

typedef union vec2_u {
    f32 elements[2];
    struct {
        union {
            f32 x, t, s, u;
        };
        union {
            f32 y, g, t, v;
        };
    };
} vec2;

typedef struct vec3_u {
    union {
        f32 elements[3];
        struct {
            union {
                f32 x, r, s, u;
            };
            union {
                f32 y, g, t, v;
            };
            union {
                f32 z, b, p, w;
            };
        };
    };
} vec3;

typedef union vec4_u {
#if defined(SUSE_SMID)
    alignas(16) __m128 data;
#endif
    alignas(16) f32 elements[4];
    union {
        struct {
            union {
                f32 x, r, s;
            };
            union {
                f32 y, g, t;
            };
            union {
                f32 z, b, p;
            };
            union {
                f32 w, a, q;
            };
        };
    };
} vec4;

typedef vec4 quat;

typedef union mat4_u {
    alignas(16) f32 data[16];
#if defined(SUSE_SMID)
    alignas(16) vec4 rows[4];
#endif
} mat4;