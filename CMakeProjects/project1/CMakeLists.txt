cmake_minimum_required(VERSION 4.0)
project(Project1 C)

set(CMAKE_C_STANDARD 11)

# Gather source files for the library
file(GLOB_RECURSE PROJECT1_SRC CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Create a static library
add_library(project1_lib STATIC ${PROJECT1_SRC})

# Add lib/ so project1.h and test.h can be found by other targets
target_include_directories(project1_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Optional: Link math library
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(project1_lib PUBLIC ${MATH_LIBRARY})
endif()

# Optional: Windows console
if (WIN32)
    target_link_options(project1_lib PRIVATE -mconsole)
endif()









