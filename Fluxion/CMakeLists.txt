cmake_minimum_required(VERSION 3.20)

project(Fluxion)

# Packages
find_package(glfw3 3.4 REQUIRED)

add_library(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw3 glad)
target_include_directories(${PROJECT_NAME} PUBLIC ./)

add_subdirectory(Fluxion)
