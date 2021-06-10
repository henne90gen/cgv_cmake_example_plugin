# Example Plugin Project

## Building

```bash
mkdir build && cd build
cmake -D CGV_DIR=<cgv path (see "Include Options" for more details)> ..
make
```

## CGV Include Options

### find_package

```cmake
find_package(CGV REQUIRED)
```

```bash
cmake -D CGV_DIR=<cgv install path>/lib ..
```

- Advantages
    - a simple download with the install directory could be provided
- Disadvantages
    - install targets have to be maintained
    - debugging of framework code is not possible (cxx files are not available)

### add_subdirectory

```cmake
add_subdirectory(${CGV_DIR} ${CMAKE_BINARY_DIR}/cgv)
```

```bash
cmake -D CGV_DIR=<cgv git path> ..
```

- Advantages
    - all targets of the cgv framework are available
    - debugging is easily possible, since whole source tree is imported
- Disadvantages
    - user has to checkout and build the cgv framework
