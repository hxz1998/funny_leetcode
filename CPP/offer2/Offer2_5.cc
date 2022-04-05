/**
 * Created by Xiaozhong on 2022/3/21.
 * Copyright (c) 2022/3/21 Xiaozhong. All rights reserved.
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
    int covert(const string &word) {
        int ret = 0;
        for (char c: word) {
            ret |= 1 << (c - 'a');
        }
        return ret;
    }

public:
    int maxProduct(vector<string> &words) {
        unordered_map<string, int> mapper;
        for (const string &word: words) {
            mapper[word] = covert(word);
        }
        int n = static_cast<int>(words.size());
        int ans = 0;
        for (int left = 0; left < n; ++left) {
            for (int right = left + 1; right < n; ++right) {
                if ((mapper[words[left]] & mapper[words[right]]) == 0)
                    ans = max(ans, static_cast<int>(words[left].size() * words[right].size()));
            }
        }
        return ans;
    }
};