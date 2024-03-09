#ifndef EVENT_PROPAGATE_HPP
#define EVENT_PROPAGATE_HPP

#include "Dispatcher.hpp"
#include "Listener.hpp"

namespace event
{
    template <class T>
    class Propagator :
        public Dispatcher<T>,
        public Listener<T>
    {
        public:
            void onEvent(T* event)
            {
                // event->addPropagation(this)
                this->dispatch(event);
            }
    };
}

#endif
