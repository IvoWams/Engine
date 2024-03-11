#include "event/Listener.cpp"
#include "event/Dispatcher.hpp"
#include "engine/event/TickEvent.hpp"
#include "engine/event/EngineTimingEvent.hpp"
#include "engine/Engine.hpp"

using engine::Engine;
using namespace ::event;
using namespace ::engine::event;

using EngineTimingEventTypeEnum::INITIALISATION;
using EngineTimingEventTypeEnum::START;
using EngineTimingEventTypeEnum::ITERATION;
using EngineTimingEventTypeEnum::STOP;
using EngineTimingEventTypeEnum::CLEANUP;

class EngineOperator :
    public Listener<TickEvent>,
    public Listener<EngineTimingEvent<INITIALISATION>>,
    public Listener<EngineTimingEvent<START>>,
    public Listener<EngineTimingEvent<ITERATION>>,
    public Listener<EngineTimingEvent<STOP>>,
    public Listener<EngineTimingEvent<CLEANUP>>
{
    public:
        EngineOperator(){}

        void onEvent(TickEvent* tickEvent){ printf("tickEvent(%lld)\n", tickEvent->duration); };
        void onEvent(EngineTimingEvent<INITIALISATION>*){ printf("Main::Initialisation()\n"); };
        void onEvent(EngineTimingEvent<START>*){ printf("Main::Start()\n"); };
        void onEvent(EngineTimingEvent<ITERATION>*){ printf("Main::Iteration()\n"); };
        void onEvent(EngineTimingEvent<STOP>*){ printf("Main::Stop()\n"); };
        void onEvent(EngineTimingEvent<CLEANUP>*){ printf("Main::Cleanup()\n"); };
};

int main()
{
    auto o = new EngineOperator();
    auto engine = Engine::getInstance();

    ((Dispatcher<TickEvent>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<INITIALISATION>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<START>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<ITERATION>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<STOP>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<CLEANUP>>*)engine)->addListener(o);

    engine->initialise();
    engine->run();
    engine->cleanup();
}