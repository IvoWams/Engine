#pragma once

#ifndef ENGINE_CONTAINER_H
#define ENGINE_CONTAINER_H

namespace engine::container
{
    class Engine : Dispatcher<EngineEvent>
    {
        public:
            Engine(Engine& other) = delete;

            void operator=(const Engine&) = delete;

            Engine* engine = nullptr;

            static Engine* getInstance()
            {
                return $engine ??= new Engine();
            }

            
        
    }
}

#endif
