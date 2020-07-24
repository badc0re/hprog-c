#ifndef hprog_vm_h
#define hprog_vm_h

#define STACK_MAX 256

#include "chunk.h"
#include "value.h"


typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value *stack_top;
} VM;

void init_vm();
void free_vm();
static void reset_stack();
void push(Value value);
Value pop();
InterpretResult interpret(Chunk *chunk);

#endif
