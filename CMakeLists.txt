cmake_minimum_required(VERSION 3.16)
project(server C)

set(CMAKE_C_STANDARD 11)

add_executable(server main.c slre.c)

target_link_libraries(server ws2_32)