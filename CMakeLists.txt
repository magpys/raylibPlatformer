cmake_minimum_required(VERSION 4.0)
project(platformer C)

set(CMAKE_C_STANDARD 11)

# Find raylib
find_package(raylib REQUIRED)

# Add your executable
add_executable(platformer main.c
        entities.h
        entities.c
        constants.h
        camera.h
        camera.c)

# Link raylib
target_link_libraries(platformer raylib)

# macOS specific frameworks (needed for raylib)
if(APPLE)
    target_link_libraries(platformer "-framework OpenGL")
    target_link_libraries(platformer "-framework Cocoa")
    target_link_libraries(platformer "-framework IOKit")
    target_link_libraries(platformer "-framework CoreVideo")
    target_link_libraries(platformer "-framework CoreAudio")
endif()
