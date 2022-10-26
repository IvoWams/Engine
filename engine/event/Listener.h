#ifndef ENGINE_EVENT_LISTENER_H
#define ENGINE_EVENT_LISTENER_H

namespace engine::event {

    template <class T>
    class Listener {
    public:
        virtual void onEvent(T* event) = 0;
    };

}

#endif
