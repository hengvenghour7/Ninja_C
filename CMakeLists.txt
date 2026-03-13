cmake_minimum_required(VERSION 3.10)
project(MyGame C)

# Use C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find libraries
find_package(raylib REQUIRED)
find_package(cJSON REQUIRED)

# Source files
file(GLOB SOURCES src/*.c)

# Create executable
add_executable(main ${SOURCES})

# Output executable in CMake project directory
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Link libraries
target_link_libraries(main
    raylib
    cjson
)