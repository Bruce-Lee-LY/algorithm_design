# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 18:39:37 on Wed, May 25, 2022
#
# Description: run sample script

#!/bin/bash

set -euo pipefail

WORK_PATH=$(cd $(dirname $0) && pwd) && cd $WORK_PATH

rm -rf log && mkdir -p log/greedy log/divide_conquer log/dynamic_programming log/backtrack

# greedy
nohup $WORK_PATH/output/greedy/coin_change > log/greedy/coin_change.log 2>&1 &
nohup $WORK_PATH/output/greedy/dijkstra > log/greedy/dijkstra.log 2>&1 &

# divide_conquer
nohup $WORK_PATH/output/divide_conquer/fibonacci_sequence_dc > log/divide_conquer/fibonacci_sequence_dc.log 2>&1 &
nohup $WORK_PATH/output/divide_conquer/quick_sort > log/divide_conquer/quick_sort.log 2>&1 &
nohup $WORK_PATH/output/divide_conquer/merge_sort > log/divide_conquer/merge_sort.log 2>&1 &

# dynamic_programming
nohup $WORK_PATH/output/dynamic_programming/backpack_01 > log/dynamic_programming/backpack_01.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/bellman_ford > log/dynamic_programming/bellman_ford.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/fibonacci_sequence_dp > log/dynamic_programming/fibonacci_sequence_dp.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/floyd > log/dynamic_programming/floyd.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/longest_common_subsequence > log/dynamic_programming/longest_common_subsequence.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/longest_common_substring > log/dynamic_programming/longest_common_substring.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/longest_palindrome_substring > log/dynamic_programming/longest_palindrome_substring.log 2>&1 &
nohup $WORK_PATH/output/dynamic_programming/SPFA > log/dynamic_programming/SPFA.log 2>&1 &

# backtrack
nohup $WORK_PATH/output/backtrack/arrange_string > log/backtrack/arrange_string.log 2>&1 &
nohup $WORK_PATH/output/backtrack/hungary_binary_graph > log/backtrack/hungary_binary_graph.log 2>&1 &
nohup $WORK_PATH/output/backtrack/KM_binary_graph > log/backtrack/KM_binary_graph.log 2>&1 &
