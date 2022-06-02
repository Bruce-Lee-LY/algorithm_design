// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: arrange string

#include <string>

#include "common.h"

static std::string s_str = "abcd";

static void arrange_string(const std::string &str, const std::string &tmp) {
    if (!str.length()) {
        printf("%s\n", tmp.c_str());
        return;
    }

    for (size_t i = 0; i < str.length(); ++i) {
        std::string news = str.substr(0, i) + str.substr(i + 1);
        arrange_string(news, tmp + str[i]);
    }
}

int main() {
    unsigned long long start = get_time_us();
    arrange_string(s_str, "");
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
