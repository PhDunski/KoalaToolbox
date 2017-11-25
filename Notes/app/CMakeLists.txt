
add_executable(Notes main.cpp)
include_directories(${NOTE_INCLUDE_DIRS} ${CMAKE_BIN_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC noteLib)
target_link_libraries(${PROJECT_NAME} noteLib)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)