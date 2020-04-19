cmake_minimum_required(VERSION 3.15)
project(leetcode_training C)

set(CMAKE_C_STANDARD 11)

add_executable(leetcode_training
        CountingElements/CountElem.c
        data_structure/stack/stack.c
        data_structure/stack/stack.h
        data_structure/uthash/include/uthash.h
        )
