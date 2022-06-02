// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: longest common subsequence

#include <string>
#include <vector>

#include "common.h"

static std::string s_str1 = "abcbcdef";
static std::string s_str2 = "abcdef";

static int longest_common_subsequence(const std::string &str1, const std::string &str2) {
    int len1 = static_cast<int>(str1.size());
    int len2 = static_cast<int>(str2.size());
    std::vector<std::vector<int>> tab(len1 + 1, std::vector<int>(len2 + 1));
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0) {
                tab[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                tab[i][j] = tab[i - 1][j - 1] + 1;
            } else {
                tab[i][j] = std::max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
    }

    return tab[len1][len2];
}

int main() {
    unsigned long long start = get_time_us();
    printf("%d\n", longest_common_subsequence(s_str1, s_str2));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
