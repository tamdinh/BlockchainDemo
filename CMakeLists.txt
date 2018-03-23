cmake_minimum_required(VERSION 3.8)
project(SimpleBlockchainInC)
message(STATUS "start running cmake...")

set(CMAKE_CXX_STANDARD 17)

set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
#set(OPENSSL_LIBRARIES /usr/local/opt/openssl/lib)
#set(OPENSSL_INCLUDE_DIRS /usr/local/opt/openssl/include/openssl)

# add extra include directories
#include_directories(/usr/local/include)

set(SOURCE_FILES main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h Hash.h utilities/json.hh)
find_package(openssl 2.2.7 COMPONENTS system filesystem REQUIRED)
if (OPENSSL_FOUND)
    message(STATUS "openssl_INCLUDE_DIRS: ${openssl_INCLUDE_DIRS}")
    message(STATUS "openssl_LIBRARIES: ${openssl_LIBRARIES}")
    message(STATUS "openssl_VERSION: ${openssl_VERSION}")
    message(STATUS "found openssl, include them ...")
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

find_package(Boost 1.66.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

add_executable(SimpleBlockchainInC ${SOURCE_FILES})

if (OPENSSL_FOUND)
    target_link_libraries( SimpleBlockchainInC ${OPENSSL_CRYPTO_LIBRARY} )
endif()

if(Boost_FOUND)

    target_link_libraries(SimpleBlockchainInC ${Boost_LIBRARIES})

endif()