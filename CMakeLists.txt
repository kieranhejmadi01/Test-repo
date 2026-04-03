cmake_minimum_required(VERSION 3.14.1)
project(test_repo LANGUAGES CXX)

set(EXECUTABLE_NAME myApp)

add_executable(${EXECUTABLE_NAME} "a.cpp")