#include "Inputtable.hpp"

namespace ui::element
{
    void Inputtable::onEvent(KeyEvent<KeyDirection::PRESS>* key)
    {    
        if (key->getKeyCode() < 0 || key->getKeyCode() > 255) {
            return;
        }

        bool& isPressed = keyBuffer[key->getKeyCode()];

        if (! isPressed) {
            Dispatcher<InputEvent>::dispatch(new InputEvent(key, key->getKeyCode()));
            isPressed = true;
        }
    }

    void Inputtable::onEvent(KeyEvent<KeyDirection::RELEASE>* key)
    {
        if (key->getKeyCode() < 0 || key->getKeyCode() > 255) {
            return;
        }

        bool& isPressed = keyBuffer[key->getKeyCode()];

        if (isPressed) {
            isPressed = false;
        }
    }

}