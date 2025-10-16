cmake_minimum_required(VERSION 4.0)
project(MyCProjects C)

set(CMAKE_C_STANDARD 11)

# Include all .c files recursively from the src directory
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/*.c"
)

# Add the executable (main.c + all .c files from src)
add_executable(MyCProjects
        main.c
        ${SRC_FILES}
)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(MyCProjects PUBLIC ${MATH_LIBRARY})
endif()

# Add include directories so headers in src/ can be found
target_include_directories(MyCProjects PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

# Force console subsystem on Windows (optional)
if (WIN32)
    target_link_options(MyCProjects PRIVATE -mconsole)
endif()
