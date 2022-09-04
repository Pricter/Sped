#include "smath.h"
#include "platform/platform.h"

#include <math.h>
#include <stdlib.h>

static b8 rand_seeded = false;

f32 ssin(f32 x) {
    return sinf(x);
}

f32 scos(f32 x) {
    return cosf(x);
}

f32 stan(f32 x) {
    return tanf(x);
}

f32 sacos(f32 x) {
    return acosf(x);
}

f32 ssqrt(f32 x) {
    return sqrtf(x);
}

f32 sabs(f32 x) {
    return fabsf(x);
}

i32 srandom() {
    if (!rand_seeded) {
        srand((u32)platform_get_absolute_time());
        rand_seeded = true;
    }
    return rand();
}

i32 srandom_in_range(i32 min, i32 max) {
    if (!rand_seeded) {
        srand((u32)platform_get_absolute_time());
        rand_seeded = true;
    }
    return (rand() % (max - min + 1)) + min;
}

f32 fsrandom() {
    return (float)srandom() / (f32)RAND_MAX;
}

f32 fsrandom_in_range(f32 min, f32 max) {
    return min + ((float)srandom() / ((f32)RAND_MAX / (max - min)));
}