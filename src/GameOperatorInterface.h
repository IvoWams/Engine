#ifndef ENGINE_GAMEOPERATORINTERFACE_H
#define ENGINE_GAMEOPERATORINTERFACE_H

#include <chrono>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std::chrono;

namespace engine
{
    struct Progressable
    {
        time_point<high_resolution_clock> last = high_resolution_clock::now();

        virtual void advance(long nanoSeconds) = 0;

        void update()
        {
            auto current = high_resolution_clock::now();
            duration<double, std::milli> duration_ms = current - last;
            auto duration_int = duration_cast<nanoseconds>(current - last).count();
            advance(duration_int);
            last = current;
        }
    };

    // Game logic proceeds in time
    struct GameOperatorInterface : public Progressable
    {
        
    };
}

#endif