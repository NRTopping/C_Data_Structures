cmake_minimum_required (VERSION 3.4)

# define a macro for defining an option
macro(nds_set_option var default type docstring)
  if (NOT DEFINED ${var})
    set(${var} ${default})
  endif()
  set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# Determine whether to create a debug or release build
nds_set_option(CMAKE_BUILD_TYPE Release String "Choose the type of build (Release or Debug)")

# Project Name
project (NDS)

# Set Version Number
set (NDS_VERSION_MAJOR 1)
set (NDS_VERSION_MINOR 0)

# Add Header Files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add Source Files
add_subdirectory(src/NDS)

# 
