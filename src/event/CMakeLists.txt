add_library(
    event
    Listener.hpp
    Dispatcher.hpp
    Listener.cpp
    Event.hpp
    Event.cpp
    Propagator.hpp
)

project(event VERSION 0.1.0 LANGUAGES CXX)

