cmake_minimum_required(VERSION 3.20)

project(Sandbox)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Fluxion)
