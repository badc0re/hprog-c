#pragma once

#ifndef hprog_value_h
#define hprog_value_h

#include "common.h"
#include "memory.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void init_va(ValueArray* va);
void write_va(ValueArray* va, Value value);
void free_va(ValueArray* va);
void print_value(Value value);

#endif
