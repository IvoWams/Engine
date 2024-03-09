#ifndef MEMORY_RECYCLER_RECYCLERMANAGER_HPP
#define MEMORY_RECYCLER_RECYCLERMANAGER_HPP

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Slot.hpp"

using namespace std;
using std::vector;

namespace memory::recycler
{
    template <class T>
    class RecyclerManager
    {
        private:
            vector<Slot<T>*> slots;
            static RecyclerManager<T>& instance;

            RecyclerManager(){}

        public:

            RecyclerManager(RecyclerManager const&) = delete;
            void operator=(RecyclerManager<T> const&) = delete;

            static RecyclerManager<T>& getInstance()
            {
                static RecyclerManager<T> instance;
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