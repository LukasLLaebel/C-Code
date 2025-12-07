cmake_minimum_required(VERSION 4.0)
project(Miniproject3 C)

set(CMAKE_C_STANDARD 11)

# Collect all .c files in src/
file(GLOB_RECURSE Miniproject3_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(Miniproject3_lib STATIC ${Miniproject3_SRC})

target_include_directories(Miniproject3_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

