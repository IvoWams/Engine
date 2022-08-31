#ifndef APP_EVENT_PROPAGATE_H
#define APP_EVENT_PROPAGATE_H

namespace app::event
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
