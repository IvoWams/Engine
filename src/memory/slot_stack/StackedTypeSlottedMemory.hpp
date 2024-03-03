#ifndef MEMORY_STACKED_TYPE_SLOTTED_MEMORY_H
#define MEMORY_STACKED_TYPE_SLOTTED_MEMORY_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Slot.hpp"

using namespace std;
using std::vector;

namespace memory::slot_stack
{
    template <class T>
    class StackedTypeSlottedMemory
    {
        private:
            vector<Slot<T>*> slots;
            static StackedTypeSlottedMemory<T>& instance;

            StackedTypeSlottedMemory(){}

        public:

            StackedTypeSlottedMemory(StackedTypeSlottedMemory const&) = delete;
            void operator=(StackedTypeSlottedMemory<T> const&) = delete;

            static StackedTypeSlottedMemory<T>& getInstance()
            {
                static StackedTypeSlottedMemory<T> instance;
                return instance;
            }

            Slot<T>* createSlot()
            {
                for(auto slot : slots) {
                    if (! slot->active) {
                        return slot;
                    }
                }

                auto newSlot = new Slot<T>();
                slots.push_back(newSlot);
                return newSlot;
            }
    };
}

#endif