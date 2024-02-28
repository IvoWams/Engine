#ifndef ENGINE_UI_EVENT_POSITIONAL_H
#define ENGINE_UI_EVENT_POSITIONAL_H

namespace ui::event::trait
{
    class Positional
    {
        private:
            int x, y;

        public:
            Positional(int _x, int _y) : x(_x), y(_y) {}

            int getX();
            int getY();
    };
}

#endif