#include "Hoverable.hpp"

namespace ui::element
{
    void Hoverable::onEvent(MouseOverEvent<OUT>* mouseOut)
    {
        Dispatcher<HoverEvent<SETTLE>>::dispatch(new HoverEvent<SETTLE>(mouseOut, mouseOut->getTarget()));
    }

    void Hoverable::onEvent(MouseOverEvent<OVER>* mouseOver)
    {
        Dispatcher<HoverEvent<HOVER>>::dispatch(new HoverEvent<HOVER>(mouseOver, mouseOver->getTarget()));
    }
}
