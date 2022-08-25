#pragma once

#include "defines.h"

typedef enum memory_tag {
    MEMORY_TAG_UNKNOWN,
    MEMORY_TAG_ARRAY,
    MEMORY_TAG_DARRAY,
    MEMORY_TAG_DICT,
    MEMORY_TAG_RING_QUEUE,
    MEMORY_TAG_BST,
    MEMORY_TAG_STRING,
    MEMORY_TAG_APPLICATION,
    MEMORY_TAG_JOB,
    MEMORY_TAG_TEXTURE,
    MEMORY_TAG_MATERIAL_INSTANCE,
    MEMORY_TAG_RENDERER,
    MEMORY_TAG_GAME,
    MEMORY_TAG_TRANSFORM,
    MEMORY_TAG_ENTITY,
    MEMORY_TAG_ENTITY_NOD,
    MEMORY_TAG_SCENE,

    MEMORY_TAG_MAX_TAGS,
} memory_tag;

SAPI void initialize_memory();
SAPI void shutdown_memory();

SAPI void* sallocate(u64 size, memory_tag tag);
SAPI void  sfree(void* block, u64 size, memory_tag tag);
SAPI void* szero_memory(void* block, u64 size);
SAPI void* scopy_memory(void* dest, const void* source, u64 size);
SAPI void* sset_memory(void* dest, i32 value, u64 size);
SAPI char* get_memory_usage_str();