#include <stdio.h>

#include "ui/UIEventHandler.hpp"
#include "ui/element/Button.h"
#include "ui/event/derived/ClickEvent.hpp"
#include "ui/event/pure/MouseClickEvent.hpp"

using namespace ::event;
using namespace ui;
using namespace ui::element;
using namespace ui::event::pure;
using namespace ui::event::derived;

class TestListener :
    public Listener<ui::event::derived::ClickEvent>
{
    public:
        void onEvent(ClickEvent* click)
        {
            printf("A click came in for %s\n", click->getTarget()->getName().c_str());
        }
};

int main()
{
    ui::UIEventHandler uihandler;

    auto button = new Button();
    auto listener = new TestListener();

    ((Dispatcher<ClickEvent>*)button)->addListener(listener);

    auto mouseClickEvent = new MouseClickEvent<MouseClickDirection::PRESS>(1);
    auto element = new Element("name");
    auto clickEvent = new ClickEvent(mouseClickEvent, element);    

    ((Dispatcher<ClickEvent>*)button)->dispatch(clickEvent);

    // button->setHitbox(new Rectangle(1, 2, 3, 4));
    
    uihandler.root.addChild(
        new Button()
    );

    printf("eyoo\n");
}