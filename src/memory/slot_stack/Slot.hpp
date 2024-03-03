#ifndef MEMORY_SLOT_STACK_SLOT_HPP
#define MEMORY_SLOT_STACK_SLOT_HPP

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

namespace memory::slot_stack
{
    template<class T>
    class Slot
    {
        private:
        public:
            Slot()
            {
                memory = static_cast<T*>(malloc(sizeof(T)));
            };

            T* memory = nullptr;
            bool active = true;
    };
}

#endif