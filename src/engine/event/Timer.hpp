#ifndef ENGINE_EVENT_TIMER_HPP
#define ENGINE_EVENT_TIMER_HPP

#include "engine/trait/Progressable.hpp"
#include "TimerEvent.hpp"
#include <iostream>

using engine::trait::Progressable;

namespace engine::event
{
    class TimerEvent;

    class Timer :
        public Progressable,
        public Dispatcher<TimerEvent>
    {
        private:
            TimerEvent event{this};

        public:
            Timer(uint64_t _duration, bool _repeat = false) :
                duration(_duration),
                cooldown(_duration),
                repeat(_repeat)
            {
                printf("Start timer %ld\n", duration);
            }

            uint64_t duration, cooldown;
            bool repeat;

            void onEvent(TickEvent* tick)
            {
                if (cooldown < tick->duration ) {
                    dispatch(&event);
                    cooldown += duration;
                    if (repeat) {
                        // cooldown += tick->duration;
                     } else {
                        // this is a dispatcher<timerevent>
                        // and a listener<tickerevent>

                        // both need to go                        
                        printf("\nWE NEED TO GO\n");
                        // std::erase(listeners[(Dispatcher<TimerEvent>*)this], (Listener<TimerEvent>*)this);                        

                        stopListening();

                        cleanup();
                     }
                }

                cooldown -= tick->duration;
            }
    };
}

#endif