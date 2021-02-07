cmake_minimum_required(VERSION 3.0.0)
project(mj_coin)
set(CMAKE_CXX_STANDARD 17)
FIND_PACKAGE(Boost 1.54 COMPONENTS log REQUIRED)
SET(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE(Threads)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_executable(run 
                main.cpp 
                block.cpp 
                blockchain.cpp 
                json.hpp 
                sha256.cpp
                )

TARGET_LINK_LIBRARIES(run ${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
