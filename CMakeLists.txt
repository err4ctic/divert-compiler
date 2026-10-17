cmake_minimum_required(VERSION 4.3.4)
project(DivertCompiler VERSION 1.0 LANGUAGES CXX)

add_executable(compiler 
    src/compiler.cpp 
    src/lexer.cpp
)

target_include_directories(compiler PRIVATE include)