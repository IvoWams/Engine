#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

namespace event
{
    template <class T>
    class Listener
    {
        protected:
            Listener(){};
            virtual ~Listener();

        public:
            virtual void onEvent(T* event) = 0;
    };
}

#endif