set(FACTORY_EX_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Where to find the Factory example headers")
set(FACTORY_EX_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADERS Base
            Color
            Derivee1
            Derivee2)
set(SRCS Base
         Color
         Derivee1
         Derivee2
         Factory
         main)

foreach(h ${HEADERS})
    list(APPEND FACTORY_EX_HEADERS ${FACTORY_EX_INCLUDE_DIRS}/${h}.hpp)
endforeach()
foreach(s ${SRCS})
    list(APPEND FACTORY_EX_SRCS ${FACTORY_EX_SRC_DIR}/${s}.cpp)
endforeach()
add_executable(factoryExample ${FACTORY_EX_SRCS} ${FACTORY_EX_HEADERS})
include_directories(${FACTORY_EX_INCLUDE_DIRS} ${CMAKE_BIN_DIR})

target_include_directories(factoryExample PUBLIC factoryLib)
target_link_libraries(factoryExample factoryLib)
