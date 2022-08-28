#include "sstring.h"
#include "core/smemory.h"

#include "string.h"

u64 string_length(const char* str) {
    return strlen(str);
}

char* string_duplicate(const char* str) {
    u64 length = string_length(str);
    char* copy = sallocate(length + 1, MEMORY_TAG_STRING);
    scopy_memory(copy, str, length + 1);
    return copy;
}

b8 strings_equal(const char* str0, const char* str1) {
    return strcmp(str0, str1) == 0;
}