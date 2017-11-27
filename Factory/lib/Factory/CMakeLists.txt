include(Factory.cmake)

add_library(factoryLib INTERFACE)
target_include_directories(factoryLib INTERFACE ${FACTORY_INCLUDE_DIRS})
install(FILES ${KTB_HEADERS} DESTINATION include/${PROJECT_NAME})
