#include "KeyframeHandler.hpp"

namespace keyframe
{
    template <typename T>
    void KeyframeHandler<T>::add(
        T& value, 
        Keyframe<T>* keyframe
    )
    {
        keyframes[value].insert(std::pair(keyframe->start, keyframe));
    }

    template <typename T>
    void KeyframeHandler<T>::onEvent(TickEvent* tick)
    {

        // for (auto keyframelist : keyframes) {
        //     auto list = keyframelist.second;
        //     auto first = list.at(0)
        //     uint64_t firsttime = list.firstfirst;
        //
        //     auto firstframe = keyframelist
        // }
    }

}