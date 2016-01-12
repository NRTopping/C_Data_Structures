# TODO document 

# Create Unity Library
file(GLOB UNITY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Unity/src/*.c)
file(GLOB UNITY_FIXTURE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/Unity/extras/fixture/src/*.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Unity/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Unity/extras/fixture/src)

add_library(Unity ${UNITY_SRC} ${UNITY_FIXTURE_SRC})

file(GLOB SRC_FILES *.c) # TODO get rid of glob
add_executable(NDSTest ${SRC_FILES})
target_link_libraries(NDSTest NDS)
target_link_libraries(NDSTest Unity)
add_test(NDSTest NDSTest)
