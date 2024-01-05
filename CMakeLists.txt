cmake_minimum_required(VERSION 3.27)
project(experience_tracker C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(experience_tracker
        src/experience.c
        src/main.c
        src/types.h
        src/experience.h
        src/util.h
        src/util.c)
