#ifndef APP_UI_BUILDER_UIBUILDER_H
#define APP_UI_BUILDER_UIBUILDER_H

#include <string>

namespace app::ui::builder
{
    struct UIBuilder
    {
        void newElement(std::string type);
        void newInput();
        void newButton();
        void setParameter(std::string, std::string);
        void setParameter(std::string, int);
        void create();
    };
}

#endif
