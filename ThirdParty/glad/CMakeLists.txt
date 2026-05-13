cmake_minimum_required(VERSION 3.20)

add_library(glad src/glad.c
        include/KHR/khrplatform.h
        include/glad/glad.h)
target_include_directories(glad PUBLIC include)
