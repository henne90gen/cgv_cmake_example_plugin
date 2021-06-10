cmake_minimum_required(VERSION 3.14)

project(cmake_example_plugin)

#find_package(CGV REQUIRED)

add_subdirectory(${CGV_DIR} ${CMAKE_BINARY_DIR}/cgv)

add_library(my_plugin SHARED my_plugin.cpp)
target_link_libraries(my_plugin cgv_utils json cg_gamepad)
add_dependencies(my_plugin cg_fltk)
