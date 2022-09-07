#pragma once

#include "defines.h"

SAPI u64 string_length(const char* str);
SAPI char* string_duplicate(const char* str);
SAPI b8 strings_equal(const char* str0, const char* str1);
SAPI i32 string_format(char* dest, const char* format, ...);
SAPI i32 string_format_v(char* dest, const char* format, void* va_listp);