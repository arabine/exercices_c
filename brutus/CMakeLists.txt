cmake_minimum_required(VERSION 3.22)
project(brutus C)

set(CMAKE_C_STANDARD 11)

add_executable(brutus main.c md5.c)
