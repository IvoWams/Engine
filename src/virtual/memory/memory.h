#ifndef ENGINE_MEMORY_MEMORY_H
#define ENGINE_MEMORY_MEMORY_H

#define MEMORY_SIZE 64000

#include <cstdio>

namespace engine::memory
{
    struct VM
    {
        char memory[MEMORY_SIZE];
        bool free_map[MEMORY_SIZE];
        int free = MEMORY_SIZE;
    };

    void outputVm(const VM& vm)
    {
        printf("Memory free: %d\n", vm.free);
    };

    int main()
    {
        VM vm;

        outputVm(vm);

        return 0;
    };
}

#endif