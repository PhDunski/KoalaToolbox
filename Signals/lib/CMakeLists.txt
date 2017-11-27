include(Signals.cmake)

add_library(Signals INTERFACE)
target_include_directories(Signals INTERFACE ${SIGNALS_INCLUDE_DIRS})
install(FILES ${KTB_HEADERS} DESTINATION include/${PROJECT_NAME})
