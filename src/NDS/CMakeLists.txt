set(INCROOT ${PROJECT_SOURCE_DIR}/include/NDS)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/NDS)

# all source files
set(SRC 
    ${SRCROOT}/list.c
    ${INCROOT}/list.h
    ${SRCROOT}/lnode.c
    ${INCROOT}/lnode.h)

add_library(nds SHARED ${SRC})
