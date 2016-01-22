cmake_minimum_required (VERSION 2.8.7)

# Project Name
project(NDS C)

# Set Version Number
set(NDS_VERSION_MAJOR 1)
set(NDS_VERSION_MINOR 0)

# Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c1x")

enable_testing()

# Add Header Files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add Source Files
add_subdirectory(src/NDS)
add_subdirectory(test)
