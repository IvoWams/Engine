add_subdirectory(event)
add_subdirectory(trait)

add_library(
    engine
    Engine.hpp
    Stopwatch.hpp
)

# target_include_directories(engine PUBLIC ${CMAKE_SOURCE_DIR})
# target_include_directories(ui PUBLIC ../src)

set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(engine engine_event engine_trait)
