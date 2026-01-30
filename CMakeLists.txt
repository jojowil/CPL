cmake_minimum_required(VERSION 3.28)
project(CPL C)

set(CMAKE_C_STANDARD 23)

include_directories(.)

add_executable(cpl
        cpl.c
        cpl-include.h
)
