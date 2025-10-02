cmake_minimum_required(VERSION 4.0)
project(MyCProjects C)

set(CMAKE_C_STANDARD 11)

# Automatically include all C files in the folder
file(GLOB SRC_FILES "*.c")

add_executable(MyCProjects ${SRC_FILES})
# Force console subsystem on Windows
if (WIN32)
    target_link_options(MyCProjects PRIVATE -mconsole)
endif ()