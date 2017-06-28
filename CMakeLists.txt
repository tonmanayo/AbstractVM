cmake_minimum_required(VERSION 3.7)
project(abstractvm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp IOperand.hpp Operands.hpp)
add_executable(abstractvm ${SOURCE_FILES} IOperand.hpp)