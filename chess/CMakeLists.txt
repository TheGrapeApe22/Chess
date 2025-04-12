cmake_minimum_required(VERSION 3.22.1)

# project name
set(EXEC_NAME "chess")
project(${EXEC_NAME})

# set(CMAKE_BUILD_TYPE Debug)

# src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# compile to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use pkg-config to find SFML
include(FindPkgConfig)
pkg_check_modules(SFML REQUIRED sfml-graphics sfml-window sfml-system)

# make executable file
add_executable(${EXEC_NAME} ${SOURCES})

# Link SFML libraries to your executable
target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Add SFML include directories (if needed)
target_include_directories(${EXEC_NAME}  PRIVATE ${SFML_INCLUDE_DIRS})

# include headers
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/assets)

#find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
#target_link_libraries(${EXEC_NAME} sfml-graphics)

# this does nothing
# link_directories("C:/libraries/SFML/build/lib")

# include libraries
# target_link_libraries(${EXEC_NAME}
#     ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.a
#     ${CMAKE_SOURCE_DIR}/lib/libsfml-window.a
#     ${CMAKE_SOURCE_DIR}/lib/libsfml-system.a
# )
