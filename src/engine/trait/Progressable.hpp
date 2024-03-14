#ifndef ENGINE_TRAIT_PROGRESSABLE_HPP
#define ENGINE_TRAIT_PROGRESSABLE_HPP

#include "engine/Engine.hpp"
#include "event/Listener.hpp"
#include "engine/event/TickEvent.hpp"

using engine::Engine;
using ::event::Listener;
using ::engine::event::TickEvent;

namespace engine::trait
{
    class Progressable : public Listener<TickEvent>
    {
        public:
            Progressable()
            {
                ((Dispatcher<TickEvent>*)Engine::getInstance())->addListener(this);
            }

            virtual ~Progressable(){};

            void stopListening()
            {
                ((Dispatcher<TickEvent>*)Engine::getInstance())->delListener(this);
            }

            void onEvent(TickEvent* event) = 0;
    };
}

#endif
