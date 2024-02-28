#include <stdio.h>

#include "ui/UIEventHandler.hpp"
#include "ui/element/Button.h"

using namespace ui;
using namespace ui::element;

int main()
{
    ui::UIEventHandler uihandler;
    uihandler.root.addChild(
        new Button()
    );

    printf("eyoo\n");
}