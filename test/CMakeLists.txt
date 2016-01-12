# TODO document 

# Create Unity Library
file(GLOB UNITY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Unity/src/*.c)
MESSAGE(STATUS "CMAKE CURRENT SOURCE DIR: " ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Unity ${UNITY_SRC})

file(GLOB SRC_FILES *.c) # TODO get rid of glob
add_executable(NDSTest ${SRC_FILES})
target_link_libraries(NDSTest NDS)
target_link_libraries(NDSTest Unity)
add_test(NDSTest NDSTest)
