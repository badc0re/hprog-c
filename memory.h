#pragma once
#ifndef hprog_memory_h
#define hprog_memory_h

#include "common.h"

void* reallocate(void *pointer, size_t old_size, size_t new_size);

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, old_count, new_count) \
    (type *)reallocate(pointer, sizeof(type) * (old_count), \
            sizeof(type) * (new_count))

#define FREE_ARRAY(type, pointer, old_count) \
    (type *)reallocate(pointer, sizeof(type) * (old_count), 0)

#endif
