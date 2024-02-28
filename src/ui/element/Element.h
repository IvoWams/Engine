#ifndef ENGINE_UI_ELEMENT_H
#define ENGINE_UI_ELEMENT_H

#include <string>
#include <vector>

using std::string;

namespace ui::element
{
    class Element
    {
        private:
            int id;
            string name;
            // bool focus = false;
            // bool mousedown = false;
            // bool visible = false;
            std::vector<Element*> children;

        public:
            void addChild(Element*);
            std::vector<Element*>* getChildren();
            Element* query(std::string);
    };
}

#endif