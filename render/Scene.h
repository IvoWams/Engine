#ifndef RENDER_SCENE_H
#define RENDER_SCENE_H

// This containerizes the content that the renderer can use to paint the scene

namespace render
{
    struct Scene
    {
        Camera* camera;
        vector<Entity*> entities;

        // expand where needed
    }
}

#endif