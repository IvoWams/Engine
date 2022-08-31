#ifndef APP_EVENT_LISTENER_H
#define APP_EVENT_LISTENER_H

namespace app::event {

    template <class T>
    class Listener {
    public:
        virtual void onEvent(T* event) = 0;
    };

}

#endif
