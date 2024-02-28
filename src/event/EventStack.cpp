#include "EventStack.h"
#include <cstdlib>

namespace event
{
    void* EventStack::operator new(size_t size) {
        if (EventStack::unique == nullptr) {
            EventStack::unique = ::operator new(size);
        }

        return EventStack::unique;
    }

    void EventStack::operator delete(void* p) {
        if (EventStack::unique != nullptr) {
            free(EventStack::unique);
            EventStack::unique = nullptr;
        }
    }    
}