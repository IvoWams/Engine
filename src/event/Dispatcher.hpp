#ifndef EVENT_DISPATCHER_HPP
#define EVENT_DISPATCHER_HPP

#include "Listener.hpp"
#include <vector>
#include <cstdio>

namespace event
{
    using std::vector;

    template <class T>
    class Dispatcher
    {
        private:
            vector<Listener<T>*> listeners;

        protected:
            Dispatcher(){};
            virtual ~Dispatcher(){};

        public:
            Dispatcher<T>& operator()(const T &event)
            {
                dispatch(event);
            }

            void dispatch(T *event)
            {
                for (auto listener : listeners) listener->onEvent(event);
            }

            void addListener(Listener<T> *listener)
            {
                listeners.push_back(listener);
            }
    };

}

#endif
