enable_testing()
set(EXTRA_INCLUDE TestingStructs.hpp)
set(SRCS Main
         Blocking
         MultipleSlots
         Scope)
include_directories(${CATCH_INCLUDE_DIRS})
include_directories(${SIGNALS_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
foreach(s ${SRCS})
    add_executable(${s} ${CMAKE_CURRENT_SOURCE_DIR}/${s}.cpp)
    
    add_test(NAME ${s} COMMAND ${s})
endforeach()

