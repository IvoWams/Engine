#ifndef RENDER_CAMERA_H
#define RENDER_CAMERA_H

#include "../math/Vector.h"

namespace render
{
    struct Camera
    {
        math::Vector* location;
        math::Vector* lookat;        
        
        // other stuff
    };
}

#endif
