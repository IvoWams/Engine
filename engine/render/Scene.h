#ifndef ENGINE_RENDER_SCENE_H
#define ENGINE_RENDER_SCENE_H

// This containerizes the content that the renderer can use to paint the scene

#include "Camera.h"
#include <vector>
#include "Entity.h"

namespace engine::render
{
    struct Scene
    {
        Camera* camera;
        std::vector<Entity*> entities;

        // expand where needed
    };
}

#endif