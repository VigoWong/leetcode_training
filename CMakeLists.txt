cmake_minimum_required(VERSION 3.15)
project(leetcode_training C)

set(CMAKE_C_STANDARD 11)

add_executable(leetcode_training
        CountandSay/CountandSay.c
        data_structure/tree/MaxHeap.c
        data_structure/tree/MaxHeap.h
#        data_structure/tree/MinHeap.c
#        data_structure/tree/MinHeap.h
        data_structure/tree/Tree.c
        data_structure/tree/Tree.h
        data_structure/graph/Graph.h
        data_structure/graph/Graph.c
        data_structure/stack/stack.c
        data_structure/stack/stack.h
        data_structure/uthash/include/uthash.h
        )
