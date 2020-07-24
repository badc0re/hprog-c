#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    init_vm();

    Chunk chunk;

    init_chunk(&chunk);

    int a = add_constant(&chunk, 20.30);
    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, a, 1);

    int b = add_constant(&chunk, 10000000000000);
    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, b, 1);

    write_chunk(&chunk, OP_MULTIPLY, 1);

    write_chunk(&chunk, OP_RETURN, 1);

    diss_chunk(&chunk, "test chunk");

    interpret(&chunk);

    free_chunk(&chunk);
    free_vm();


    return 0;
}
