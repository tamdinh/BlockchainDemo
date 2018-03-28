cmake_minimum_required(VERSION 3.8)
project(SimpleBlockchainInC)
message(STATUS "start running cmake...")

set(CMAKE_CXX_STANDARD 17)

#set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)

# add extra include directories
include_directories(/net /utilities)

set(SOURCE_FILES main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h Hash.h
        net/client_http.h net/server_http.h net/status_code.h
        utilities/json.hh utilities/utility.h)

find_package(openssl COMPONENTS system filesystem REQUIRED)
if (OPENSSL_FOUND)
    message(STATUS "OPENSSL_INCLUDE_DIR: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OPENSSL_LIBRARIES: ${OPENSSL_LIBRARIES}")
    message(STATUS "OPENSSL_VERSION: ${OPENSSL_VERSION}")

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