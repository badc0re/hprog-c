#include <stdlib.h>
#include <stdio.h>

#include "value.h"

void init_va(ValueArray* va) {
    va->capacity = 0;
    va->count = 0;
    va->values = NULL;
}

void write_va(ValueArray* va, Value value) {
    if(va->capacity  < va->count + 1) {
        int old_capacity = va->capacity;
        va->capacity = GROW_CAPACITY(old_capacity); 
        va->values = GROW_ARRAY(Value, va->values,
                old_capacity, va->capacity);
    }
    va->values[va->count] = value;
    va->count++;
}

void free_va(ValueArray *va) {
    FREE_ARRAY(Value, va->values, va->capacity);
    // reset
    init_va(va);
}

void print_value(Value value) {
    printf("%g", value);
}
