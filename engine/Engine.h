#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "EngineStatistics.h"
#include "render/RenderInterface.h"
#include "GameOperatorInterface.h"

namespace engine
{
    class Engine
    {
        private:
            Engine(){ }
        public:
            Engine(Engine const&) = delete;
            void operator=(Engine const&) = delete;

            static Engine *getInstance()
            {
                static Engine instance;
                return &instance;
            }

            EngineStatistics statistics;
            GameOperatorInterface *gameOperator;

            // Below the engine there needs to be interaction with the OS
            // The OS is probably going to give us human interaction information, but
            // also how to open and close a windows
            void setOSHandler(){ }

            // Renderer is the base that handles outputting everything on the screen
            // The renderer itself is to be expected to get a handle on paintable entities
            // like for example the scene, or the UI, etc...
            // Renderer should be able to paint onto something that is set in the OS handler
            void setRenderer(engine::render::RenderInterface *renderer){ }

            // There are a couple of components that allows us to interact with the engine as we see
            // fit. These are primarily: keyboard and mouse. Maybe later: controller
            // Beyond this is for example the control binding
            void setHumanInteractionDeviceHandler(){ }

            // This should be a sound handling that can do two things:
            // Play a sound track, or play a sound effect on demand
            void setSoundHandler(){ }

            // Game logic should not be implemented in the engine itself, so just abstract it here
            void setGameOperator(GameOperatorInterface *_gameOperator)
            {
                gameOperator = _gameOperator;
            }

            


    };
}

#endif