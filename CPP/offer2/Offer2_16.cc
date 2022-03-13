/**
 * Created by Xiaozhong on 2022/3/13.
 * Copyright (c) 2022/3/13 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        int left = 0, right = n - 1;
        unordered_map<char, int> cnt;
        auto check = [](const unordered_map<char, int> &cnt) {
            for (auto item : cnt) {
                if (item.second > 1) return false;
            }
            return true;
        };
        while (right < n) {
            while ()
        }
    }
};