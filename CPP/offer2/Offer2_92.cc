/**
 * Created by Xiaozhong on 2022/4/15.
 * Copyright (c) 2022/4/15 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one = 0;
        int dp = 0;
        for (char c: s) {
            if (c == '0') {
                dp = min(dp + 1, one);
            } else one++;
        }
        return dp;
    }
};