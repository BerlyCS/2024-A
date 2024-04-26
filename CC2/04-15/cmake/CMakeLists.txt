# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
project(CMakeTest CXX)

set(SOURCES
    main.cpp
    funcs.cpp
)

set(HEADERS
    funcs.hpp
)

add_executable(program ${SOURCES})
