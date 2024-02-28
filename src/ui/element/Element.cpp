#include "Element.h"

namespace ui::element
{
    Element* Element::query(std::string name)
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

    std::vector<Element*>* Element::getChildren()
    {
        return &children;
    }

    void Element::addChild(Element* element)
    {
        children.push_back(element);
    }
}