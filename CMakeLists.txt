cmake_minimum_required(VERSION 3.23)
project(system_programming_EX_3_B)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(sources)

add_executable(system_programming_EX_3_B
        sources/Fraction.cpp
        sources/Fraction.hpp
        Demo.cpp
        doctest.h
        StudentTest1.cpp
        StudentTest2.cpp
        TestRunner.cpp)
