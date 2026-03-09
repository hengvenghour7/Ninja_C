cmake_minimum_required(VERSION 3.10)
project(Ninja_C C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.c")

add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Let CMake find Raylib automatically
find_package(raylib REQUIRED)

# Include headers and link library
target_link_libraries(main PRIVATE raylib)