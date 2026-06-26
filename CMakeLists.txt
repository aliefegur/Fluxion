cmake_minimum_required(VERSION 3.20)

project(Fluxion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Third-party libraries
add_subdirectory(ThirdParty)

add_subdirectory(Fluxion)
add_subdirectory(Sandbox)
