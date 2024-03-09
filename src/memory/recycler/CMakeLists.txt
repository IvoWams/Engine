add_library(
    memory_recycler
    Slot.hpp
    Recycler.hpp
    RecyclerManager.hpp
)

set_target_properties(memory_recycler PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(memory_recycler PUBLIC ${CMAKE_SOURCE_DIR})
