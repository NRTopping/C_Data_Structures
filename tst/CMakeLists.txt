# TODO document 

# Create Unity Library
file(GLOB UNITY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Unity/src/*.c)
file(GLOB UNITY_FIXTURE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/Unity/extras/fixture/src/*.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Unity/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Unity/extras/fixture/src)

add_library(Unity ${UNITY_SRC} ${UNITY_FIXTURE_SRC})

# Add a new Test macro
macro(newTest testName testSrc)
  add_executable(${testName} ${CMAKE_CURRENT_SOURCE_DIR}/${testSrc})
  target_link_libraries(${testName} NDS)
  target_link_libraries(${testName} Unity)
  add_test(${testName} ${testName})
endmacro(newTest)

# Tests
newTest(lnode_test lnode_test.c)
newTest(list_test list_test.c)

