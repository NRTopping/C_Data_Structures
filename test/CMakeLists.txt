file(GLOB SRC_FILES *.c)
add_executable(NDSTest ${SRC_FILES})
target_link_libraries(NDSTest NDS)
add_test(NDSTest NDSTest)
