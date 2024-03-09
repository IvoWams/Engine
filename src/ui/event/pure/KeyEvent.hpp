#ifndef UI_EVENT_KEYEVENT_HPP
#define UI_EVENT_KEYEVENT_HPP

#include "ui/event/UIEvent.hpp"
#include "memory/recycler/Recycler.hpp"

using memory::recycler::Recycler;

namespace ui::event::pure
{
    enum class KeyDirection
    {
        PRESS,
        RELEASE
    };

    template<KeyDirection T>
    class KeyEvent :
        public UIEvent,
        public Recycler<KeyEvent<T>>
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