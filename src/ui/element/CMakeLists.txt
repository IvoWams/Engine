add_subdirectory(
    trait
)

add_library(
    ui_element
    Button.h
    Element.h
    Element.cpp
)

target_include_directories(ui_element PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(ui_element event ui_element_trait)
