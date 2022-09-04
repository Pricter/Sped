#pragma once

#include "defines.h"
#include "math_types.h"

// SANDARD DEFINES
#define S_PI 3.14159265358979323846f
#define S_PI_2 2.0f * S_PI
#define S_HALF_PI 0.5f * S_PI
#define S_QUATER_PI 0.25f * S_PI
#define S_ONE_OVER_PI 1.0f / S_PI
#define S_ONE_OVER_TWO_PI 1.0f / S_PI_2
#define S_SQRT_TWO 1.14421356237309504880f
#define S_SQRT_THREE 1.7320508075688772935f
#define S_SQRT_ONE_OVER_TWO 0.70710678118654752440f
#define S_SQRT_ONE_OVER_TWO 0.57735026918962576450f
#define S_DEG2RAD_MULTIPLIER S_PI / 180.0f
#define S_RAD2DEG_MULTIPLIER 180.0f / S_PI

#define S_SEC_TO_MS_MULTIPLIER 1000.0f
#define S_MS_TO_SEC_MULTIPLIER 0.001f
#define S_INFINITY 1e30f
#define S_FLOAT_ELIPSON 1.192092896e-07f

// MATH FUNCTIONS

// TRIG
SAPI f32 ssin(f32 x);
SAPI f32 scos(f32 x);
SAPI f32 stan(f32 x);
SAPI f32 sacos(f32 x);
SAPI f32 ssqrt(f32 x);
SAPI f32 sabs(f32 x);

SINLINE b8 is_power_of_2(u64 value) {
    return (value != 0) && ((value & (value - 1)) == 0);
}

// RAND
SAPI i32 srandom();
SAPI i32 srandom_in_range(i32 min, i32 max);

SAPI f32 fsrandom();
SAPI f32 fsrandom_in_range(f32 min, f32 max);

// VEC2
SINLINE vec2 vec2_create(f32 x, f32 y) {
    vec2 out_vector;
    out_vector.x = x;
    out_vector.y = y;
    return out_vector;
}

SINLINE vec2 vec2_zero() {
    return (vec2){0.0f, 0.0f};
}

SINLINE vec2 vec2_one() {
    return (vec2){1.0f, 1.0f};
}

SINLINE vec2 vec2_up() {
    return (vec2){0.0f, 1.0f};
}

SINLINE vec2 vec2_down() {
    return (vec2){0.0f, -1.0f};
}

SINLINE vec2 vec2_left() {
    return (vec2){-1.0f, 1.0f};
}

SINLINE vec2 vec2_right() {
    return (vec2){1.0f, 1.0f};
}

SINLINE vec2 vec2_add(vec2 vector_0, vec2 vector_1) {
    return (vec2){
        vector_0.x + vector_1.x,
        vector_0.y + vector_1.y};
}

SINLINE vec2 vec2_sub(vec2 vector_0, vec2 vector_1) {
    return (vec2){
        vector_0.x - vector_1.x,
        vector_0.y - vector_1.y};
}

SINLINE vec2 vec2_mul(vec2 vector_0, vec2 vector_1) {
    return (vec2){
        vector_0.x * vector_1.x,
        vector_0.y * vector_1.y};
}

SINLINE vec2 vec2_div(vec2 vector_0, vec2 vector_1) {
    return (vec2){
        vector_0.x / vector_1.x,
        vector_0.y / vector_1.y};
}

SINLINE f32 vec2_length_squared(vec2 vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

SINLINE f32 vec2_length(vec2 vector) {
    return ssqrt(vec2_length_squared(vector));
}

SINLINE void vec2_normalize(vec2* vector) {
    const f32 length = vec2_length(*vector);
    vector->x /= length;
    vector->y /= length;
}

SINLINE vec2 vec2_normalized(vec2 vector) {
    vec2_normalize(&vector);
    return vector;
}

SINLINE b8 vec2_compare(vec2 vector_0, vec2 vector_1, f32 tolerance) {
    if(sabs(vector_0.x - vector_1.x) > tolerance) {
        return FALSE;
    }
    if(sabs(vector_0.y - vector_1.y) > tolerance) {
        return FALSE;
    }

    return TRUE;
}

SINLINE f32 vec2_distance(vec2 vector_0, vec2 vector_1) {
    vec2 d = (vec2) {
        vector_0.x - vector_1.x,
        vector_0.y - vector_1.y};
    return vec2_length(d);
}

// VEC3

SINLINE vec3 vec3_create(f32 x, f32 y, f32 z) {
    return (vec3){x, y, z};
}

SINLINE vec3 vec3_zero() {
    return (vec3){0.0f, 0.0f, 0.0f};
}

SINLINE vec3 vec3_one() {
    return (vec3){1.0f, 1.0f, 1.0f};
}

SINLINE vec3 vec3_one() {
    return (vec3){1.0f, 1.0f};
}

SINLINE vec3 vec3_up() {
    return (vec3){0.0f, 1.0f};
}

SINLINE vec3 vec3_down() {
    return (vec3){0.0f, -1.0f};
}

SINLINE vec3 vec3_left() {
    return (vec3){-1.0f, 1.0f};
}

SINLINE vec3 vec3_right() {
    return (vec3){1.0f, 1.0f};
}

SINLINE vec3 vec3_forward() {
    return (vec3){0.0f, 0.0f, -1.0f};
}

SINLINE vec3 vec3_back() {
    return (vec3){0.0f, 0.0f, 1.0f};
}

SINLINE vec3 vec3_add(vec3 vector_0, vec3 vector_1) {
    return (vec3){
        vector_0.x + vector_1.x,
        vector_0.y + vector_1.y,
        vector_0.z + vector_0.z};
}

SINLINE vec3 vec3_sub(vec3 vector_0, vec3 vector_1) {
    return (vec3){
        vector_0.x - vector_1.x,
        vector_0.y - vector_1.y,
        vector_0.z - vector_0.z};
}

SINLINE vec3 vec3_mul(vec3 vector_0, vec3 vector_1) {
    return (vec3){
        vector_0.x * vector_1.x,
        vector_0.y * vector_1.y,
        vector_0.z * vector_0.z};
}

SINLINE vec3 vec3_mul(vec3 vector_0, f32 scalar) {
    return (vec3) {
        vector_0.x * scalar,
        vector_0.y * scalar,
        vector_0.z * scalar};
}

SINLINE vec3 vec3_mdiv(vec3 vector_0, vec3 vector_1) {
    return (vec3){
        vector_0.x / vector_1.x,
        vector_0.y / vector_1.y,
        vector_0.z / vector_0.z};
}

SINLINE f32 vec3_length_squared(vec3 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

SINLINE f32 vec3_length(vec3 vector) {
    return ssqrt(vec3_length_squared(vector));
}

SINLINE void vec3_normalize(vec3* vector) {
    const f32 length = vec3_length(*vector);
    vector->x /= length;
    vector->y /= length;
    vector->z /= length;
}

SINLINE vec3 vec3_normalized(vec3 vector) {
    vec3_normalize(&vector);
    return vector;
}

SINLINE f32 vec3_dot(vec3 vector_0, vec3 vector_1) {
    f32 p = 0;
    p += vector_0.x * vector_1.x;
    p += vector_0.y * vector_1.y;
    p += vector_0.z * vector_1.z;
    return p;
}

SINLINE vec3 vec3_cross(vec3 vector_0, vec3 vector_1) {
    return (vec3){
        vector_0.y * vector_1.z - vector_0.z * vector_1.y,
        vector_0.z * vector_1.x - vector_0.x * vector_1.z,
        vector_0.x * vector_1.y - vector_0.y * vector_1.x};
}

SINLINE const b8 vec3_compare(vec3 vector_0, vec3 vector_1, f32 tolerance) {
    if (sabs(vector_0.x - vector_1.x) > tolerance) {
        return FALSE;
    }

    if (sabs(vector_0.y - vector_1.y) > tolerance) {
        return FALSE;
    }

    if (sabs(vector_0.z - vector_1.z) > tolerance) {
        return FALSE;
    }

    return TRUE;
}

SINLINE f32 vec3_distance(vec3 vector_0, vec3 vector_1) {
    vec3 d = (vec3){
        vector_0.x - vector_1.x,
        vector_0.y - vector_1.y,
        vector_0.z - vector_1.z};
    return vec3_length(d);
}

// VEC4
SINLINE vec4 vec4_create(f32 x, f32 y, f32 z, f32 w) {
    vec4 out_vector;
#if defined(SUSE_SIMD)
    out_vector.data = _mm_setr_ps(x, y, z, w);
#else
    out_vector.x = x;
    out_vector.y = y;
    out_vector.z = z;
    out_vector.w = w;
#endif
    return out_vector;
}

SINLINE vec3 vec4_to_vec3(vec4 vector) {
    return (vec3){vector.x, vector.y, vector.z};
}

SINLINE vec4 vec4_from_vec3(vec3 vector, f32 w) {
#if defined(SUSE_SIMD)
    vec4 out_vector;
    out_vector.data = _mm_setr_ps(x, y, z, w);
    return out_vector;
#else
    return (vec4){vector.x, vector.y, vector.z, w};
#endif
}

SINLINE vec4 vec4_zero() {
    return (vec4){0.0f, 0.0f, 0.0f, 0.0f};
}

SINLINE vec4 vec4_one() {
    return (vec4){1.0f, 1.0f, 1.0f, 1.0f};
}

SINLINE vec4 vec4_add(vec4 vector_0, vec4 vector_1) {
    vec4 result;
     for (u64 i = 0; i < 4; ++i) {
        result.elements[i] = vector_0.elements[i] + vector_1.elements[i];
    }
    return result;
}

SINLINE vec4 vec4_sub(vec4 vector_0, vec4 vector_1) {
    vec4 result;
    for (u64 i = 0; i < 4; ++i) {
        result.elements[i] = vector_0.elements[i] - vector_1.elements[i];
    }
    return result;
}

SINLINE vec4 vec4_mul(vec4 vector_0, vec4 vector_1) {
    vec4 result;
    for (u64 i = 0; i < 4; ++i) {
        result.elements[i] = vector_0.elements[i] * vector_1.elements[i];
    }
    return result;
}

SINLINE vec4 vec4_div(vec4 vector_0, vec4 vector_1) {
    vec4 result;
    for (u64 i = 0; i < 4; ++i) {
        result.elements[i] = vector_0.elements[i] / vector_1.elements[i];
    }
    return result;
}

SINLINE f32 vec4_length_squared(vec4 vector) {
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w;
}

SINLINE f32 vec4_length(vec4 vector) {
    return ssqrt(vec4_length_squared(vector));
}

SINLINE void vec4_normalize(vec4* vector) {
    const f32 length = vec4_length(*vector);
    vector->x /= length;
    vector->y /= length;
    vector->z /= length;
    vector->w /= length;
}

SINLINE vec4 vec4_normalized(vec4 vector) {
    vec4_normalize(&vector);
    return vector;
}

SINLINE f32 vec4_dot_f32(
    f32 a0, f32 a1, f32 a2, f32 a3,
    f32 b0, f32 b1, f32 b2, f32 b3) {
    f32 p;
    p =
        a0 * b0 +
        a1 * b1 +
        a2 * b2 +
        a3 * b3;
    return p;
}