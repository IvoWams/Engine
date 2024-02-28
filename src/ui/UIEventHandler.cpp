#include "UIEventHandler.hpp"

namespace ui
{
    void UIEventHandler::onEvent(KeyEvent<KeyDirection::PRESS>* pressEvent)
    {
        printf("%s\n", __func__);
    }

    void UIEventHandler::onEvent(KeyEvent<KeyDirection::RELEASE>* releaseEvent)
    {
        printf("%s\n", __func__);
    }

    void UIEventHandler::onEvent(MouseClickEvent<MouseClickDirection::PRESS>* pressEvent)
    {
        printf("%s\n", __func__);
    }

    void UIEventHandler::onEvent(MouseClickEvent<MouseClickDirection::RELEASE>* releaseEvent)
    {
        printf("%s\n", __func__);
    }

    void UIEventHandler::onEvent(MouseMoveEvent* moveEvent)
    {
        printf("%s\n", __func__);
    }

}