/**
 * Created by Xiaozhong on 2022/4/9.
 * Copyright (c) 2022/4/9 Xiaozhong. All rights reserved.
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
    void backtrack(vector<vector<int>> &ans, vector<int> &buffer, const int n, int start, int k) {
        if (k == 0) {
            ans.push_back(buffer);
            return;
        }
        for (int next = start + 1; next <= n; ++next) {
            buffer.push_back(next);
            backtrack(ans, buffer, n, next, k - 1);
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> buffer;
        for (int start = 1; start <= n - k + 1; ++start) {
            buffer.push_back(start);
            backtrack(ans, buffer, n, start, k);
            buffer.pop_back();
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.combine(4, 2);
}