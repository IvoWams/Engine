#ifndef ENGINE_UI_ELEMENT_H
#define ENGINE_UI_ELEMENT_H

#include <string>
#include <vector>

using std::string;

namespace engine::ui::element
{
    struct Element
    {
        int id;
        string name;
        bool focus = false;
        bool mousedown = false;
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