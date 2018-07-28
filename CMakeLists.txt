cmake_minimum_required(VERSION 3.10)
project(webServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(webServer main.cpp csapp.h rio.h rio.cpp opensocket.cpp opensocket.h)