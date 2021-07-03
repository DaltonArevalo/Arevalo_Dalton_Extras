cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/external/date/include")

add_executable(main main.cpp node.h dcList.h person.h personOperation.h date.h date.cpp ${PROJECT_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
