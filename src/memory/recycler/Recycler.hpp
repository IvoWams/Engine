#ifndef MEMORY_RECYCLER_RECYCLER_HPP
#define MEMORY_RECYCLER_RECYCLER_HPP

#include <assert.h>

#include "Slot.hpp"

namespace memory::recycler
{
    template <class T>
    static vector<Slot<T>*> slots;

    template <class T>
    static Slot<T>* createSlot()
    {
        for(auto slot : slots<T>) {
            if (! slot->active) {
                return slot;
            }
        }

        auto newSlot = new Slot<T>();
        slots<T>.push_back(newSlot);
        return newSlot;
    }

    template <class T>
    class Recycler      // Intentionally no constructor
    {
        Slot<T>* slot;  // Intentionally uninitialized

        public:
            void operator delete(void* p)
            {
#ifndef NDEBUG
                assert(static_cast<T*>(p)->slot != nullptr);
#endif
                static_cast<T*>(p)->slot->active = false;
            }

            void* operator new(size_t size)
            {
                auto slot = recycler::createSlot<T>();
                slot->active = true;
                slot->memory->slot = slot;
                return slot->memory;
            }
    };
}

#endif
