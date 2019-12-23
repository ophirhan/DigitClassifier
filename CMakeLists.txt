cmake_minimum_required(VERSION 3.12)
project(ex1)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex1 main.cpp Matrix.cpp Activation.cpp Dense.h Dense.cpp MlpNetwork.cpp)
add_subdirectory(tests)