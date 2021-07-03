cmake_minimum_required(VERSION 3.0.0)
project(double_linked_list VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(double_linked_list main.cpp nodo.h nodo.cpp lista_doble_enlazada.h lista_doble_enlazada.cpp menu menu.cpp menu_option menu_option.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
