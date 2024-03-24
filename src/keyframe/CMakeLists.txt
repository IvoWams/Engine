add_subdirectory(algorithm)

add_library(
    keyframe
    Keyframe.hpp
    KeyframeHandler.hpp
    KeyframeHandler.cpp
)

set_target_properties(keyframe PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(keyframe keyframe_algorithm)