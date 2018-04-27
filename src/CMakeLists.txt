project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES Block.h Hash.h Blockchain.h common.h endian.h)
set(SOURCE_FILES
        Block.cpp Blockchain.cpp)

#SSL lib
set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
find_package(openssl COMPONENTS system filesystem REQUIRED)
if (OPENSSL_FOUND)
    message(STATUS "OPENSSL_INCLUDE_DIR: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIBRARIES: ${OPENSSL_LIBRARIES}")
    message(STATUS "OPENSSL_VERSION: ${OPENSSL_VERSION}")

    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

#if (EXISTS ${SOURCE_FILES})
#    message(STATUS "Add static library")
#    # The library contains header and source files.
#    add_library(${CMAKE_PROJECT_NAME}_lib STATIC
#        ${SOURCE_FILES}
#        ${HEADER_FILES}
#    )
#else()
#    message(STATUS "Add interface only")
#    # The library only contains header files.
#    add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)
#endif()

add_library(${CMAKE_PROJECT_NAME}_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        )

if (OPENSSL_FOUND)
    target_link_libraries(${CMAKE_PROJECT_NAME}_lib ${OPENSSL_CRYPTO_LIBRARY} )
endif()