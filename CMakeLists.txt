cmake_minimum_required(VERSION 3.21)
project(Hash_table C)

set(CMAKE_C_STANDARD 23)

add_executable(Hash_table main.c hash_table.c hash_table.h error.h)
