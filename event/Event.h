#ifndef APP_EVENT_EVENT_H
#define APP_EVENT_EVENT_H

#include <cstddef>

namespace app::event {

    struct Event {

        int age = 0;

        Event()
        {
            // get a timestamp from the engine ? for animation purposes or something
            // age = time();
        }
    /*
        static void* unique;

        void* operator new(size_t size);
        void operator delete(void* p);
    */
    };

}


#endif //BACKTOCPP_EVENT_H
