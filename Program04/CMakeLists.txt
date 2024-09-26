cmake_minimum_required(VERSION 3.29)
project(Program04)

set(CMAKE_CXX_STANDARD 20)

add_executable(Program04 main.cpp
        OverloadDemo.h
        OverloadDemo.cpp
        ../Program05/main.cpp
        ../Program05/Package.h
        ../Program05/Package.cpp)
