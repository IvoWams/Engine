#ifndef ENGINE_RENDER_UI_H
#define ENGINE_RENDER_UI_H

#include <vector>

namespace engine::render
{
    struct UI
    {
        // Base class for all the UI components

        // These are the main components, they may have children
        std::vector<UI*> rootElements;



    };
}

#endif 