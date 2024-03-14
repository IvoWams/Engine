add_library(
    debug
    DebugOutput.hpp
)

set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(debug engine event)
