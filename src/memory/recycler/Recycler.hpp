#ifndef MEMORY_RECYCLER_RECYCLER_HPP
#define MEMORY_RECYCLER_RECYCLER_HPP

#include "RecyclerManager.hpp"
#include "Slot.hpp"

namespace memory::recycler
{
    template <class T>
    class Recycler
    {
        private:
            Slot<T>* slot;

        public:
            static void operator delete(void* p)
            {
                static_cast<T*>(p)->slot->active = false;
            }

            void* operator new(size_t size)
            {
                auto slot = RecyclerManager<T>::getInstance().createSlot();
                slot->active = true;
                slot->memory->slot = slot;
                return slot->memory;
            }
    };
}

#endif
