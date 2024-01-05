cmake_minimum_required(VERSION 3.27)
project(experience_tracker C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)

include_directories(.)

add_executable(experience_tracker
        src/experience.c
        src/main.c
        src/types.h
        src/experience.h
        src/util.h
        src/util.c)

target_link_libraries(experience_tracker ${CURSES_LIBRARIES})
target_include_directories(experience_tracker PRIVATE ${CURSES_INCLUDE_DIRS})