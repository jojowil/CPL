cmake_minimum_required(VERSION 3.28)
project(CPL C)

set(CMAKE_C_STANDARD 23)

include_directories(.)

add_executable(cpl
        cpl-strings.c
        cpl.c
        cpl-util.c
        cpl-functions.c
        cpl-error.c
        cpl-directives.c
        cpl-vars.c
        cpl-args.c
        cpl-files.c
        cpl-labels.c
        cpl-parse.c
        cpl-scanner.c)
