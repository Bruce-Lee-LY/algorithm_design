# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 18:39:37 on Wed, May 25, 2022
#
# Description: cmake for algorithm design

cmake_minimum_required (VERSION 3.8)

project (algorithm_design LANGUAGES CXX)

set (CMAKE_VERBOSE_MAKEFILE ${VERBOSE_MAKEFILE})

set (CMAKE_CXX_FLAGS "-std=c++11")
set (CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g2 -ggdb")
set (CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")

set (CMAKE_EXE_LINKER_FLAGS "-Wl,--as-needed")

add_compile_options (
    -Wall
    -Werror
    -Wextra
    -Wswitch-default
    -Wfloat-equal
    -Wshadow
    -Wcast-qual
)

include_directories (
    ${PROJECT_SOURCE_DIR}/src/common
    ${PROJECT_SOURCE_DIR}/src/greedy
    ${PROJECT_SOURCE_DIR}/src/divide_conquer
    ${PROJECT_SOURCE_DIR}/src/dynamic_programming
    ${PROJECT_SOURCE_DIR}/src/backtrack
    ${PROJECT_SOURCE_DIR}/src/branch_bound
)

# greedy
add_executable (coin_change ${PROJECT_SOURCE_DIR}/src/greedy/coin_change.cpp)
add_executable (dijkstra ${PROJECT_SOURCE_DIR}/src/greedy/dijkstra.cpp)

install (TARGETS coin_change dijkstra RUNTIME DESTINATION greedy)

# divide_conquer
add_executable (fibonacci_sequence_dc ${PROJECT_SOURCE_DIR}/src/divide_conquer/fibonacci_sequence.cpp)
add_executable (quick_sort ${PROJECT_SOURCE_DIR}/src/divide_conquer/quick_sort.cpp)
add_executable (merge_sort ${PROJECT_SOURCE_DIR}/src/divide_conquer/merge_sort.cpp)

install (TARGETS fibonacci_sequence_dc quick_sort merge_sort RUNTIME DESTINATION divide_conquer)

# dynamic_programming
add_executable (backpack_01 ${PROJECT_SOURCE_DIR}/src/dynamic_programming/backpack_01.cpp)
add_executable (bellman_ford ${PROJECT_SOURCE_DIR}/src/dynamic_programming/bellman_ford.cpp)
add_executable (fibonacci_sequence_dp ${PROJECT_SOURCE_DIR}/src/dynamic_programming/fibonacci_sequence.cpp)
add_executable (floyd ${PROJECT_SOURCE_DIR}/src/dynamic_programming/floyd.cpp)
add_executable (longest_common_subsequence ${PROJECT_SOURCE_DIR}/src/dynamic_programming/longest_common_subsequence.cpp)
add_executable (longest_common_substring ${PROJECT_SOURCE_DIR}/src/dynamic_programming/longest_common_substring.cpp)
add_executable (longest_palindrome_substring ${PROJECT_SOURCE_DIR}/src/dynamic_programming/longest_palindrome_substring.cpp)
add_executable (SPFA ${PROJECT_SOURCE_DIR}/src/dynamic_programming/SPFA.cpp)

install (TARGETS backpack_01 bellman_ford fibonacci_sequence_dp floyd longest_common_subsequence
    longest_common_substring longest_palindrome_substring SPFA 
    RUNTIME DESTINATION dynamic_programming
)

# backtrack
add_executable (arrange_string ${PROJECT_SOURCE_DIR}/src/backtrack/arrange_string.cpp)
add_executable (hungary_binary_graph ${PROJECT_SOURCE_DIR}/src/backtrack/hungary_binary_graph.cpp)
add_executable (KM_binary_graph ${PROJECT_SOURCE_DIR}/src/backtrack/KM_binary_graph.cpp)

install (TARGETS arrange_string hungary_binary_graph KM_binary_graph RUNTIME DESTINATION backtrack)
