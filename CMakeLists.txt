cmake_minimum_required(VERSION 3.7)
project(ArbolAVL2_0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h Archivo.cpp Archivo.h)
add_executable(ArbolAVL2_0 ${SOURCE_FILES})