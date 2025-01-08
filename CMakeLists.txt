cmake_minimum_required(VERSION 3.28.3)
project(ImageReader)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

execute_process(
        COMMAND git clone -b SDL2 "https://github.com/libsdl-org/SDL" sdl
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
add_subdirectory(build/libs/sdl libs/sdl/build)

add_subdirectory(viewer)
