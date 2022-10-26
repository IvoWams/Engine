#ifndef ENGINE_RENDER_RENDERINTERFACE_H
#define ENGINE_RENDER_RENDERINTERFACE_H

#include "Scene.h"
#include "UI.h"

namespace engine::render
{
    struct RenderInterface
    {
        virtual void renderScene(Scene* scene){}
        virtual void renderUI(UI* ui){}
    };
}

#endif
