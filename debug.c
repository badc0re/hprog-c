#include "debug.h"
#include "value.h"
#include <stdio.h>

void diss_chunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for(int offset = 0; offset < chunk->count;) {
        offset = diss_instructs(chunk, offset);
    }
}

static int simple_instruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

static int constant_instruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d'", name, constant);
    print_value(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

int diss_instructs(Chunk *chunk, int offset) {
    printf("%04d ", offset); 
    uint8_t instruction = chunk->code[offset];
    switch(instruction) {
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        default:
            printf("Uknown opcode %d\n", instruction);
            return offset + 1;
    }
}