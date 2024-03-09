#include "event/Listener.hpp"
#include "engine/event/TickEvent.hpp"
#include "engine/event/EngineTimingEvent.hpp"
#include "engine/Engine.hpp"

using engine::Engine;
using namespace ::event;
using namespace ::engine::event;

class EngineOperator :
    public Listener<TickEvent>,
    public Listener<EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>>,
    public Listener<EngineTimingEvent<EngineTimingEventTypeEnum::START>>,
    public Listener<EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>>,
    public Listener<EngineTimingEvent<EngineTimingEventTypeEnum::STOP>>,
    public Listener<EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>>
{
    public:
        EngineOperator(){}

        void onEvent(TickEvent* tickEvent){ printf("tickEvent(%lld)\n", tickEvent->duration); };
        void onEvent(EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>*){ printf("Main::Initialisation()\n"); };
        void onEvent(EngineTimingEvent<EngineTimingEventTypeEnum::START>*){ printf("Main::Start()\n"); };
        void onEvent(EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>*){ printf("Main::Iteration()\n"); };
        void onEvent(EngineTimingEvent<EngineTimingEventTypeEnum::STOP>*){ printf("Main::Stop()\n"); };
        void onEvent(EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>*){ printf("Main::Cleanup()\n"); };
};

int main()
{
    auto o = new EngineOperator();
    auto engine = Engine::getInstance();

    ((Dispatcher<TickEvent>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::START>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::STOP>>*)engine)->addListener(o);
    ((Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>>*)engine)->addListener(o);

    engine->initialise();
    engine->run();
    engine->cleanup();
}