cmake_minimum_required(VERSION 4.0)
project(Miniproject2 C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Include dependencies 
include(cmake/mtest.cmake)

#add_subdirectory(src)
enable_testing()
#add_subdirectory(test)



# >-- MY CHANGE --->

# Collect all source files
file(GLOB_RECURSE Miniproject2_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/test/"
)

# Create a static library
add_library(Miniproject2_lib STATIC ${Miniproject2_SRC})

# Add include directory for headers
target_include_directories(Miniproject2_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
    ${CMAKE_CURRENT_SOURCE_DIR}/test/
)

