#include "event/Listener.cpp"
#include "event/Dispatcher.hpp"
#include "engine/event/TickEvent.hpp"
#include "engine/event/EngineTimingEvent.hpp"
#include "engine/Engine.hpp"
#include "engine/event/Timer.hpp"

// linux:
#include <unistd.h> 
#include <iostream>

using engine::Engine;
using namespace ::event;
using namespace ::engine::event;

class Quitter : public Listener<TimerEvent>
{
    public:
        Quitter() {}
        ~Quitter() {}

        int pings = 10;

        void onEvent(TimerEvent* event)
        {
            if (pings < 0) {
                printf("Halting engine...\n");
                auto engine = Engine::getInstance();
                engine->running = false;
            } else {
                pings --;
                printf("Ping %d\n", pings);
            }
        }
};

int main()
{
    // lets create a game loop or something

    auto engine = Engine::getInstance();
    auto timer = new Timer(2000000, false);
    auto quitter = new Quitter();
    timer->addListener(quitter);

    ((Dispatcher<TickEvent>*)engine)->addListener(timer);

    engine->initialise();
    engine->run();
    engine->cleanup();
}