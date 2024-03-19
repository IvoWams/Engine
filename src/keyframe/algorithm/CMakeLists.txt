add_library(
    keyframe_algorithm
    KeyframeAlgorithm.hpp
    Linear.hpp
    Linear.cpp
)

set_target_properties(keyframe_algorithm PROPERTIES LINKER_LANGUAGE CXX)
