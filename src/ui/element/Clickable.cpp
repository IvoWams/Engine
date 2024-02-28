#include "Clickable.hpp"

namespace ui::element
{
    void Clickable::onEvent(MouseClickEvent<MouseClickDirection::PRESS>* event)
    {
        clicking = true;
        Dispatcher<ClickEvent>::dispatch(new ClickEvent(event));
    }

    void Clickable::onEvent(MouseClickEvent<MouseClickDirection::RELEASE>* event)
    {
        clicking = false;
    }
}