
add_executable(Notes main.cpp)
include_directories(${NOTE_INCLUDE_DIRS} ${CMAKE_BIN_DIR})

target_include_directories(Notes PUBLIC noteLib)
target_link_libraries(Notes noteLib)
install(TARGETS Notes
        RUNTIME DESTINATION bin)
