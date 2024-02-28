#ifndef ENGINE_UI_EVENT_KEYEVENT_H
#define ENGINE_UI_EVENT_KEYEVENT_H

#include "ui/event/UIEvent.hpp"

namespace ui::event::pure
{
    enum class KeyDirection
    {
        PRESS,
        RELEASE
    };

    template<KeyDirection T>
    class KeyEvent :
        public UIEvent
    {
        private:
            int keyCode;

        public:
            KeyEvent(int _keyCode) :
                keyCode(_keyCode)
            {};

            int getKeyCode()
            {
                return keyCode;
            }
    };
}

#endif