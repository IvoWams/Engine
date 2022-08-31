#ifndef APP_EVENT_DISPATCHER_H
#define APP_EVENT_DISPATCHER_H

#include "Listener.h"
#include <vector>
#include <cstdio>

namespace app::event
{
    using std::vector;

    template <class T>
    class Dispatcher
    {
        private:
            vector<Listener<T>*> listeners;

        public:
            Dispatcher<T>& operator()(const T& event)
            {
                dispatch(event);
            }

            void dispatch(T* event)
            {
                for (auto listener : listeners) listener->onEvent(event);
            }

            void addListener(Listener<T>* listener)
            {
                listeners.push_back(listener);
            }
    };

}

#endif //APP_DISPATCHER_H
