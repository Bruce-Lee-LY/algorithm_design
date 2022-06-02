// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: longest palindrome substring

#include <string>
#include <vector>

#include "common.h"

static std::string s_str = "hello, world";

static std::string longest_palindrome_substring(const std::string &str) {
    int len = static_cast<int>(str.size());
    std::vector<std::vector<int>> tab(len, std::vector<int>(len, 0));
    std::string res;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; i + j < len; ++j) {
            int k = i + j;
            if (i == 0) {
                tab[j][k] = 1;
            } else if (i == 1) {
                tab[j][k] = (str[j] == str[k]);
            } else {
                tab[j][k] = (str[j] == str[k] && tab[j + 1][k - 1]);
            }
            if (tab[j][k] && i + 1 > static_cast<int>(res.size())) {
                res = str.substr(j, i + 1);
            }
        }
    }

    return res;
}

int main() {
    unsigned long long start = get_time_us();
    printf("%s\n", longest_palindrome_substring(s_str).c_str());
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
