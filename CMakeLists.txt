cmake_minimum_required(VERSION 3.6)
project(HashTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES
    Flags.h
    Node.h
    HashTable.h
    HashTable.cpp
    catch.hpp
    tests.cpp)

add_executable(HashTable ${SOURCE_FILES})
target_link_libraries(HashTable ${CMAKE_SOURCE_DIR}/libHashTable.a)
set_target_properties(HashTable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )
