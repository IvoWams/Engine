#ifndef ENGINE_ENGINE_HPP
#define ENGINE_ENGINE_HPP

#include "event/Dispatcher.hpp"
#include "engine/event/TickEvent.hpp"
#include "engine/event/EngineTimingEvent.hpp"
#include "Stopwatch.hpp"

#include <chrono>

using event::Dispatcher;
using engine::event::TickEvent;
using engine::event::EngineTimingEvent;
using engine::event::EngineTimingEventTypeEnum;

namespace engine
{
    class Engine :
        public Dispatcher<TickEvent>,
        public Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>>,
        public Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::START>>,
        public Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>>,
        public Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::STOP>>,
        public Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>>
    {
        private:
            Engine(){};

            static Engine& instance;

            Stopwatch stopwatchThreshold, stopwatchTicker, stopwatchEngine;

        public:
            Engine(Engine const&) = delete;
            void operator=(Engine const&) = delete;            
            virtual ~Engine(){};

            bool running = true;

            uint64_t maxIterations = 10;
            uint64_t iterations = 0;

            int tickThreshold = 100;
            int tickThresholdCount = tickThreshold;

            static Engine* getInstance()
            {
                static Engine instance;
                return &instance;
            }

            void initialise()
            {
                Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>>
                    ::dispatch(new EngineTimingEvent<EngineTimingEventTypeEnum::INITIALISATION>());
            }

            void run()
            {
                Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::START>>
                    ::dispatch(new EngineTimingEvent<EngineTimingEventTypeEnum::START>());

                long long duration = 0;
                auto tickEvent = new TickEvent(0);
                stopwatchThreshold.start();
                stopwatchTicker.start();
                stopwatchEngine.start();

                while (running) {
                    iterations++;

                    Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>>
                        ::dispatch(new EngineTimingEvent<EngineTimingEventTypeEnum::ITERATION>());

                    tickThresholdCount -= stopwatchThreshold.timer();

                    if (tickThresholdCount < 0) {
                        tickThresholdCount += tickThreshold;
                        tickEvent->duration = stopwatchTicker.timer();
                        Dispatcher<TickEvent>::dispatch(tickEvent);
                    }

                    // if (iterations >= maxIterations) {
                    //     running = false;
                    // }
                }

                Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::STOP>>
                    ::dispatch(new EngineTimingEvent<EngineTimingEventTypeEnum::STOP>());
            }

            void cleanup()
            {
                Dispatcher<EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>>
                    ::dispatch(new EngineTimingEvent<EngineTimingEventTypeEnum::CLEANUP>());
            }
        
    };
}

#endif
