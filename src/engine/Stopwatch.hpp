#ifndef ENGINE_STOPWATCH_HPP
#define ENGINE_STOPWATCH_HPP

#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::microseconds;

namespace engine
{
    class Stopwatch
    {
        private:
            time_point<system_clock> timeStart, timeStop;

        public:
            Stopwatch(){};
            virtual ~Stopwatch(){};           

            void start()
            {
                timeStart = high_resolution_clock::now();
            }

            uint64_t timer(bool reset = true)
            {
                if (! reset) {
                    return duration_cast<microseconds>(high_resolution_clock::now() - timeStart).count();
                }

                stop();
                auto result = duration();
                start();

                return result;
            }

            void stop()
            {
                timeStop = high_resolution_clock::now();
            }

            uint64_t duration()
            {
                return duration_cast<microseconds>(timeStop - timeStart).count();
            }
    };
}

#endif