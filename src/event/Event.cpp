#include "Event.hpp"
#include <cstdlib>

namespace event
{
    Event* Event::getParent()
    {
        return parent;
    }
}
