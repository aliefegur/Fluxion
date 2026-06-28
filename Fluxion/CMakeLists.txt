cmake_minimum_required(VERSION 3.20)

project(Fluxion)

# Packages
find_package(glfw3 3.4 REQUIRED)
find_package(spdlog 1.17 REQUIRED)

add_library(${PROJECT_NAME}
        Fluxion/Core/Log.cpp
        Fluxion/Core/Log.h
        Fluxion/Core/Window/WindowSpecification.h
        Fluxion/Core/Window/Window.cpp
        Fluxion/Core/Window/Window.h
        Fluxion/Core/Application.cpp
        Fluxion/Core/Application.h
        Fluxion/Core.h
        Fluxion/Fluxion.h
        Fluxion/Core/EntryPoint.h
        Fluxion/Core/Events/Event.h
        Fluxion/Core/Events/ApplicationEvent.h
        Fluxion/Core/Events/KeyEvent.h
        Fluxion/Core/Events/MouseEvent.h)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw3 glad)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC ./)
target_precompile_headers(${PROJECT_NAME} PRIVATE fpch.h)

if (UNIX)
    target_sources(${PROJECT_NAME} PRIVATE
            Fluxion/Platform/GLFW/GLFWWindow.h
            Fluxion/Platform/GLFW/GLFWWindow.cpp)
endif ()
