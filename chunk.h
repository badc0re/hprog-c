#pragma once
#ifndef hprog_chunk_h
#define hprog_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

typedef enum {
    OP_RETURN,
    OP_CONSTANT
} OpCode;

typedef struct {
    uint8_t* code;
    int count; // current size
    int capacity; // total size
    ValueArray constants;
} Chunk;

void init_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte);
void free_chunk(Chunk* chunk);
int add_constant(Chunk* chunk, Value value);

#endif 
