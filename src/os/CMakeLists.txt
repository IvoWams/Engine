IF (WIN32)
    add_subdirectory(windows)
ENDIF ()

IF (UNIX)
    add_subdirectory(linux)
ENDIF ()

add_library(
    os
    OsHandler.hpp
    WindowHandler.h
    WindowParameter.h
)


