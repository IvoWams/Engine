#ifndef ENGINE_EVENT_LISTENER_H
#define ENGINE_EVENT_LISTENER_H

namespace event {

    template <class T>
    class Listener {
        protected:
            Listener(){};

        public:
            virtual void onEvent(T* event) = 0;
    };

}

#endif
