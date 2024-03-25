#ifndef KEYFRAME_ALGORITHM_LINEAR_HPP
#define KEYFRAME_ALGORITHM_LINEAR_HPP

#include "KeyframeAlgorithm.hpp"
#include "memory/recycler/Recycler.hpp"

using memory::recycler::Recycler;
using keyframe::Keyframe;

namespace keyframe::algorithm
{
    template <typename T>
    class Linear final :
        public KeyframeAlgorithm<T>,
        public Recycler<Linear<T>>
    {
        protected:
            void progress(float percentage, Keyframe<T>* keyframe) override;

        public:
            explicit Linear() = default;
            ~Linear() override = default;
    };
}

#endif