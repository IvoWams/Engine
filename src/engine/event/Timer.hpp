#ifndef ENGINE_EVENT_TIMER_HPP
#define ENGINE_EVENT_TIMER_HPP

#include "engine/trait/Progressable.hpp"
#include "TimerEvent.hpp"

using engine::trait::Progressable;

namespace engine::event
{
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

            };

            uint64_t duration, cooldown;
            bool repeat;

            void onEvent(TickEvent* tick)
            {
                cooldown -= tick->duration;                

                if (cooldown <= 0) {
                    dispatch(&event);
                    if (repeat) {
                        cooldown += duration;
                     } else {
                        cleanup(this);
                     }
                }
            }
    };
}

#endif