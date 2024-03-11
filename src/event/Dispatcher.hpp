#ifndef EVENT_DISPATCHER_HPP
#define EVENT_DISPATCHER_HPP

#include "Listener.hpp"
#include <vector>
#include <map>
#include <cstdio>

#include <typeinfo>
#include <iostream>

namespace event
{
    using std::vector;
    using std::map;

    template <class T>
    class Dispatcher
    {
        private:
            static map<Dispatcher<T>*, vector<Listener<T>*>> listeners;

        protected:
            Dispatcher(){};
            virtual ~Dispatcher(){};

        public:
            Dispatcher<T>& operator()(const T &event)
            {
                dispatch(event);
            }

            void dispatch(T*event)
            {
                for (auto listener : listeners[this]) listener->onEvent(event);
            }

            void addListener(Listener<T>* listener)
            {
                listeners[this].push_back(listener);
            }

            void delListener(Listener<T>* listener)
            {
                std::erase(listeners[this], listener);
            }

            static void cleanup(Listener<T>* listener)
            {
                for (auto dispatcher : listeners) {
                    dispatcher.first->delListener(listener);
                }
            }
    };

    template <class T>
    map<Dispatcher<T>*, vector<Listener<T>*>> Dispatcher<T>::listeners;
}

#endif
