#ifndef MEMORY_SLOTSTACKMEMORY_HPP
#define MEMORY_SLOTSTACKMEMORY_HPP

#include "StackedTypeSlottedMemory.hpp"
#include "Slot.hpp"

namespace memory::slot_stack
{
    template <class T>
    class SlotStackMemory
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
                auto slot = StackedTypeSlottedMemory<T>::getInstance().createSlot();
                slot->active = true;
                slot->memory->slot = slot;
                return slot->memory;
            }
    };
}

#endif
