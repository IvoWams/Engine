add_library(
    memory_slot_stack
    Slot.hpp
    SlotStackMemory.hpp
    StackedTypeSlottedMemory.hpp
)

set_target_properties(memory_slot_stack PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(memory_slot_stack PUBLIC ${CMAKE_SOURCE_DIR})
