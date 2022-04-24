/**
 * Created by Xiaozhong on 2022/4/7.
 * Copyright (c) 2022/4/7 Xiaozhong. All rights reserved.
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
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = static_cast<int>(asteroids.size());
        if (n == 0) return {};
        vector<int> stk;
        stk.push_back(asteroids[0]);
        function<void(int)> insert = [&](int num) {
            if (stk.empty() ||
                num > 0 && stk.back() < 0 ||
                num * stk.back() > 0)
                stk.push_back(num);
            else if (num + stk.back() == 0)
                // 方向相对，而且可抵消
                stk.pop_back();
            else {
                // 方向相对，不可抵消
                while (!stk.empty() && stk.back() * num < 0 && stk.back() > 0 && abs(stk.back()) < abs(num)) {
                    stk.pop_back();
                }
                if (!stk.empty() && stk.back() + num == 0) stk.pop_back();
                else if (stk.empty() || stk.back() * num > 0) stk.push_back(num);
            }
        };
        for (int idx = 1; idx < n; ++idx) {
            insert(asteroids[idx]);
        }
        return stk;
    }
};

int main() {
    vector<int> asteroids = {10, 2, -5};
    Solution s;
    s.asteroidCollision(asteroids);
}