#ifndef ENGINE_UI_ELEMENT_H
#define ENGINE_UI_ELEMENT_H

#include <string>
#include <vector>

namespace engine::ui
{
    struct Element
    {
        // Base class for all UI elements

        int id;
        std::string name;
        bool focus = false;
        bool blur = true;
        bool mousedown = false;
        bool mouseup = true;
        bool visible = false;

        std::vector<Element*> children;
        Element* query(std::string name)
        {
            for (auto child : children) {
                if (child->name == name)
                    return child;

                auto ccchild = child->query(name);
                if (ccchild != nullptr)
                    return ccchild;                    
            }

            return nullptr;
        }
    };
}

#endif