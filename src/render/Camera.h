#ifndef ENGINE_RENDER_CAMERA_H
#define ENGINE_RENDER_CAMERA_H

#include "engine/math/Vector.h"

namespace engine::render
{
    struct Camera
    {
        engine::math::Vector* location;
        engine::math::Vector* lookat;        
        
        // other stuff
    };
}

#endif
