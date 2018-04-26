project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES Block.h Hash.h)
set(SOURCE_FILES
        Block.cpp )

if (EXISTS ${SOURCE_FILES})
    message(STATUS "Add static library")
    # The library contains header and source files.
    add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
    )
else()
    message(STATUS "Add interface only")
    # The library only contains header files.
    add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)
endif()

#add_library(${CMAKE_PROJECT_NAME}_lib STATIC
#        ${SOURCE_FILES}
#        ${HEADER_FILES}
#        )