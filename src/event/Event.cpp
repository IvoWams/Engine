#include "Event.h"
#include <cstdlib>

namespace event
{
    Event* Event::getParent()
    {
        return parent;
    }
}
