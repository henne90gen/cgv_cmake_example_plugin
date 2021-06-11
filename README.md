# Example Plugin Project

## Creating CMakeLists.txt

The CGV framework uses [CMake](https://cmake.org/cmake/help/latest/) as its build system. In order to use the CGV
framework and create a plugin for it, it is recommended to use CMake as well. The first step for any CMake project is
creating a `CMakeLists.txt` like this:

```cmake
cmake_minimum_required(VERSION 3.15)
project(cmake_example_plugin)

find_package(CGV REQUIRED)

add_library(my_plugin SHARED my_plugin.cpp)
target_link_libraries(my_plugin cgv_gl)
add_dependencies(my_plugin cg_fltk crg_stereo_view)
```

## CGV Include Options

In your root `CMakeLists.txt`, place the following `find_packge` call:

```cmake
find_package(CGV REQUIRED)
```

Additionally, the cmake-specific environment variable `CGV_DIR` has to be set to a valid location of the CGV framework.
This can either be the checked out git repository, or a downloaded install directory.

### Install Version

A portable, pre-compiled version can be downloaded from GitHub Releases. After extracting, the folder has the following
structure:

```
- cgv-install
    - include
    - lib
    - cgv-config.cmake
```

The `include` sub-folder contains the header files of the framework whereas lib contains the pre-built `.dll` files. To
use this installed version, just call cmake with `CGV_DIR` set to point to the `cgv-install` folder.

```bash
cmake -D CGV_DIR=<cgv install path> ..
```

Finally, to start your plugin call the `cgv_viewer` executable that's inside the `lib` folder with the following
arguments:

````bash
CGV_INSTALL_DIR="<cgv install path>"
PLUGIN_BUILD_DIR="<path to cmake build directory>"
$CGV_INSTALL_DIR/lib/cgv_viewer \
  plugin:cg_fltk \
  plugin:crg_stereo_view \
  plugin:$PLUGIN_BUILD_DIR/my_plugin \
  type(shader_config):shader_path='$CGV_INSTALL_DIR/include/cgv-libs/cgv_gl/glsl'
````

### Git Version

```cmake
find_package(CGV REQUIRED)
```

```bash
cmake -D CGV_DIR=<cgv git path> ..
```

## Referencing CGV Libraries

Libraries that are being provided by the CGV framework can be linked against just like any CMake targets by
using `target_link_libraries`. The only special case are other plugins that will only be used at runtime, such
as `cg_fltk` or `crg_stereo_view`. Those plugins have to be specified as dependencies of the custom plugins target. This
way, they will be built before building the custom plugin. Example:

```cmake
target_link_libraries(my_plugin cgv_gl)
add_dependencies(my_plugin cg_fltk crg_stereo_view)
```

## Building

```bash
mkdir build && cd build
cmake -D CGV_DIR=<cgv path (see "Include Options" for more details)> ..
make
```
