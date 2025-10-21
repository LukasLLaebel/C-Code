cmake_minimum_required(VERSION 4.0)
project(MyCProjects C)

set(CMAKE_C_STANDARD 11)

# Add subproject as a library
add_subdirectory(CMakeProjects/project1)

# Find all top-level src files
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.c")

# Add the top-level executable
add_executable(MyCProjects
    main.c
    ${SRC_FILES}
)

# Link with the project1 library
target_link_libraries(MyCProjects PRIVATE project1_lib)

# Add include directory for subproject headers
target_include_directories(MyCProjects PRIVATE
    ${CMAKE_SOURCE_DIR}/CMakeProjects/project1/lib
)

# Optional: Link math if needed
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(MyCProjects PUBLIC ${MATH_LIBRARY})
endif()

if (WIN32)
    target_link_options(MyCProjects PRIVATE -mconsole)
endif()

