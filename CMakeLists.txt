cmake_minimum_required(VERSION 3.27)
project(CompilerV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompilerV2 main.cpp
        Token.hpp
        Token.cpp
        Scanner.hpp
        Scanner.cpp
        Parser.hpp
        Parser.cpp
        t1.i
        t2.i
        t18.i
        t3.i
        t9.i
        t17.i
        t4.i)
