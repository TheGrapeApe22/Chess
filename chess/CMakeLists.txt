cmake_minimum_required(VERSION 3.31.1)

# project name
set(EXEC_NAME "chess")
project(${EXEC_NAME})

# set(CMAKE_BUILD_TYPE Debug)

# src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# compile to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# make executable file
add_executable(${EXEC_NAME} ${SOURCES})

# include headers
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/assets)

# this does nothing
# link_directories("C:/libraries/SFML/build/lib")

# include libraries
target_link_libraries(${EXEC_NAME}
    ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.a
    ${CMAKE_SOURCE_DIR}/lib/libsfml-window.a
    ${CMAKE_SOURCE_DIR}/lib/libsfml-system.a
)
