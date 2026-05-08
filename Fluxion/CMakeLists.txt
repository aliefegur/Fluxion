cmake_minimum_required(VERSION 3.20)

project(Fluxion)

add_library(${PROJECT_NAME} src/Hello.h src/Hello.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC src)
