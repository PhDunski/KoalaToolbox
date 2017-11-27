
set(NOTE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Where to find the library headers")
set(NOTE_BUILD_DIR ${CMAKE_CURRENT_BUILD_DIR})
set(NOTE_SRC_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HPP Sequence)

set(CPP Sequence)
foreach(s ${CPP})
	list(APPEND SRCS ${NOTE_SRC_DIRS}/${s}.cpp)
endforeach()
foreach(h ${HPP})
	list(APPEND HEADERS ${NOTE_INCLUDE_DIRS}/${h}.hpp)
endforeach()
add_library(noteLib ${SRCS} ${HEADERS})
target_include_directories(noteLib PUBLIC ${NOTE_INCLUDE_DIRS})
set_target_properties(noteLib PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(noteLib PUBLIC $<BUILD_INTERFACE:${NOTE_INCLUDE_DIRS}>
								          $<INSTALL_INTERFACE:include/note> 
)
install(TARGETS noteLib
    ARCHIVE DESTINATION lib)
install(FILES  ${KTB_HEADERS}  DESTINATION include/${PROJECT_NAME})