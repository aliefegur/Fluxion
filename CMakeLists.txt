cmake_minimum_required(VERSION 3.20)

project(Fluxion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy
)

# Third-party libraries
add_subdirectory(ThirdParty)

find_package(spdlog 1.17 REQUIRED)

add_subdirectory(Fluxion)
add_subdirectory(Sandbox)
