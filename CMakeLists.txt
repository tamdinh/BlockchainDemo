cmake_minimum_required(VERSION 3.8)
project(SimpleBlockchainInC)
message(STATUS "start running cmake...")

set(CMAKE_CXX_STANDARD 17)

#set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
#set(OPENSSL_LIBRARIES /usr/local/opt/openssl/lib)
#set(OPENSSL_INCLUDE_DIRS /usr/local/opt/openssl/include/openssl)

# add extra include directories
#include_directories(/usr/local/include)

set(SOURCE_FILES main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h Hash.h Utilities/json.hh)

find_package(openssl REQUIRED)
if (OPENSSL_FOUND)

    message(STATUS "found openssl, include them ...")
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

add_executable(SimpleBlockchainInC ${SOURCE_FILES})
target_link_libraries( SimpleBlockchainInC ${OPENSSL_CRYPTO_LIBRARY} )