#include "Event.h"
#include <cstdlib>

namespace engine::event {

    // void* Event::unique = nullptr;

    /**
     * The problem is that if an event is dispatched, and during this dispatching another event is fired
     * the Event will be overwritten.
     * @param size_t size
     * @return void*
     */
    /*
    void* Event::operator new(size_t size) {
        if (Event::unique == nullptr) {
            Event::unique = ::operator new(size);
        }

        return Event::unique;
    }

    void Event::operator delete(void* p) {
        if (Event::unique != nullptr) {
            free(Event::unique);
            Event::unique = nullptr;
        }
    }
    */

}
