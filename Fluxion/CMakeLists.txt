cmake_minimum_required(VERSION 3.20)

project(Fluxion)

# Packages
find_package(glfw3 3.4 REQUIRED)

add_library(${PROJECT_NAME}
        Fluxion/Core/Log.h
        Fluxion/Core/Log.cpp
        Fluxion/Core/Window/WindowSpecification.h
        Fluxion/Core/Window/Window.h
        Fluxion/Core/Window/Window.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw3 glad)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC ./)
target_precompile_headers(${PROJECT_NAME} PRIVATE fpch.h)

if (UNIX)
    target_sources(${PROJECT_NAME} PRIVATE
            Fluxion/Platform/GLFW/GLFWWindow.h
            Fluxion/Platform/GLFW/GLFWWindow.cpp)
endif ()
