#ifndef MEMORY_SLOT_STACK_SLOT_HPP
#define MEMORY_SLOT_STACK_SLOT_HPP

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

namespace memory::recycler
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

            virtual ~Slot()
            {
                printf("oi\n");
            }

            T* memory = nullptr;
            bool active = true;
    };
}

#endif