/**
 * Created by Xiaozhong on 2020/10/10.
 * Copyright (c) 2020/10/10 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 判断 dist 是不是 src 的子序列
    bool isSubsequence(const string &src, const string &dist) {
        int j = 0;
        for (int i = 0; i < dist.length() && j < src.length(); ++i) {
            if (src[j] == dist[i]) ++j;
        }
        return j == src.length();
    }

public:
    int findLUSlength(vector<string> &strs) {
        int ans = -1;
        sort(strs.begin(), strs.end(), [&](const string &lhs, const string &rhs) {
            return lhs.length() < rhs.length();
        });
        bool flag = false;
        for (int i = 0, j; i < strs.size(); ++i) {
            for (j = 0; j < strs.size(); ++j) {
                if (j == i) continue;
                if (isSubsequence(strs[i], strs[j])) break;
            }
            if (j == strs.size()) ans = max(ans, (int) strs[i].length());
        }
        return ans;
    }
};