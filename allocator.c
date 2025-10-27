#include <stddef.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>

#define SIZE 4096

struct Arena {
    char *buffer; // Base address of the memory arena
    size_t totalSize; // Total size of the memory (4KB by default)
    size_t offset; // Current allocation position
};

    struct Arena global_arena = {0};

void *alloc(size_t size) {

    if (global_arena.buffer == NULL) {
        global_arena.buffer = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        global_arena.totalSize = SIZE;
        global_arena.offset = 0;
    }

    if (global_arena.offset + size > global_arena.totalSize) {
        printf("Out of memory");
        exit(1);
    }

    void *allocated = global_arena.buffer + global_arena.offset;
    global_arena.offset += size;
    return allocated;
}

int main() {
    int *x = (int*)alloc(sizeof(int) * 10); // Example Allocation
    return 0;
}
