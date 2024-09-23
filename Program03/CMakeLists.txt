cmake_minimum_required(VERSION 3.29)
project(Program03)

set(CMAKE_CXX_STANDARD 20)

add_executable(Program03 main.cpp
        Customer.h
        Customer.cpp
        Order.h
        Order.cpp
        Product.h
        Product.cpp)
