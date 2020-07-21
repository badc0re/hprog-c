#pragma once
#ifndef hprog_debug_h
#define hprog_debug_h

#include "chunk.h"

void diss_chunk(Chunk* chunk, const char* name);
int diss_instructs(Chunk *chunk, int offset);
static int simple_instruction(const char* name, int offset);
static int constant_instruction(const char* name, Chunk* chunk, int offset);

#endif
