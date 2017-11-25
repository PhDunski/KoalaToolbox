include(Signals.cmake)

add_library(Signals INTERFACE)
target_include_directories(Signals INTERFACE ${SIGNALS_INCLUDE_DIRS})
