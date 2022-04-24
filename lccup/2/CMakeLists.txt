cmake_minimum_required(VERSION 3.5)
project(lccup-02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp )
add_executable(lccup-02 ${SOURCE_FILES})