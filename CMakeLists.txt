cmake_minimum_required(VERSION 3.28.3)
project(image-reader)

file(MAKE_DIRECTORY libs)

execute_process(
        COMMAND git clone -b SDL2 "https://github.com/libsdl-org/SDL" sdl2
        WORKING_DIRECTORY libs)
add_subdirectory(libs/sdl2 libs/sdl2)

add_subdirectory(core)


add_executable(main core/main.c)

target_link_libraries(main core)
