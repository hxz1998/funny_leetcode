/**
 * Created by Xiaozhong on 2020/12/4.
 * Copyright (c) 2020/12/4 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] > rhs[1];
        });
        vector<int> todo(intervals.size(), 2);
        int ans = 0, t = intervals.size();
        while (--t >= 0) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];
            for (int p = s; p < s + m; ++p) {
                for (int i = 0; i <= t; ++i) {
                    if (todo[i] > 0 && p <= intervals[i][1])
                        todo[i]--;
                }
                ans++;
            }
        }
        return ans;
    }
};