/**
 * Created by Xiaozhong on 2022/4/19.
 * Copyright (c) 2022/4/19 Xiaozhong. All rights reserved.
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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stk;
        int n = static_cast<int>(temperatures.size());
        vector<int> ans(n);
        for (int idx = n - 1; idx >= 0; --idx) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[idx]) stk.pop();
            if (stk.empty()) ans[idx] = 0;
            else ans[idx] = stk.top() - idx;
            stk.push(idx);
        }
        return ans;
    }
};

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    s.dailyTemperatures(temperatures);
}