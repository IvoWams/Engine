add_library(
    engine_event
    EngineEvent.hpp
    EngineTimingEvent.hpp
    TickEvent.hpp
)

set_target_properties(engine_event PROPERTIES LINKER_LANGUAGE CXX)
