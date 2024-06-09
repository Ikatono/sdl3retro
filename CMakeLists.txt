cmake_minimum_required(VERSION 3.5)
project(sdl3retro)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an option to switch between a system sdl library and a vendored SDL library
option(MYGAME_VENDORED "Use vendored libraries" OFF)

if(MYGAME_VENDORED)
    # This assumes you have added SDL as a submodule in vendored/SDL
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL3 package,
    # 2. look for the SDL3-shared component, and
    # 3. fail if the shared component cannot be found.
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

# Create your game executable target as usual
add_executable(sdl3retro WIN32
    src/main.cpp
    src/input.cpp
    src/core.cpp
    )

# Link to the actual SDL3 library.
target_link_libraries(sdl3retro PRIVATE SDL3::SDL3)

target_include_directories(sdl3retro PRIVATE include)
