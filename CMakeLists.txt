cmake_minimum_required(VERSION 3.7)
project(abstractvm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(SOURCE_FILES main.cpp IOperand.hpp Operands.hpp VMFactory.cpp VMFactory.hpp Stackstuff.cpp Stackstuff.hpp ErrorHandle.cpp ErrorHandle.hpp)
add_executable(abstractvm ${SOURCE_FILES} IOperand.hpp)