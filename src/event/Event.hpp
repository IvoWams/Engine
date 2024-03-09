#ifndef ENGINE_EVENT_EVENT_H
#define ENGINE_EVENT_EVENT_H

#include <cstddef>

namespace event
{
    class Event
    {
        private:
            Event* parent = nullptr;

        protected:
            Event() {};
            Event(Event* _parent) : parent(_parent) {};

        public:
            virtual ~Event(){};
            
            Event* getParent();
    };
}

#endif
