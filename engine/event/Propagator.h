#ifndef ENGINE_EVENT_PROPAGATE_H
#define ENGINE_EVENT_PROPAGATE_H

namespace engine::event
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
