cmake_minimum_required(VERSION 3.15)
project(cmake_example_plugin)

find_package(CGV REQUIRED)

add_library(my_plugin SHARED my_plugin.cpp)
target_link_libraries(my_plugin cgv_gl)
add_dependencies(my_plugin cg_fltk crg_stereo_view cgv_viewer)

# set_ide_params(my_plugin "plugin:cg_fltk plugin:crg_stereo_view plugin:${CMAKE_BINARY_DIR}/Debug/my_plugin")
