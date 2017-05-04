cmake_minimum_required(VERSION 2.8)

project(espeak_test)

SET(CMAKE_CXX_COMPILER "g++")
set( CMAKE_BUILD_TYPE "Debug" )
SET( CMAKE_CXX_FLAGS "-O3 -std=c++11" )

add_library( myEspeak SHARED readString.cpp )


add_executable( et espeakTest.cpp )

target_link_libraries( et myEspeak )