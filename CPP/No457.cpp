/**
 * Created by Xiaozhong on 2020/9/26.
 * Copyright (c) 2020/9/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        if (nums.empty()) return false;
        int n = nums.size();
        auto next = [&](int x) { return ((x + nums[x]) % n + n) % n; };

        for (int i = 0; i < nums.size(); ++i) {
            int j = i, count = 1;
            vector<bool> visited(n, false);
            while (j < n) {
                if (visited[j]) break;
                visited[j] = true;
                int nextIndex = next(j);
                if (nums[j] * nums[nextIndex] < 0) break;
                if (nextIndex == i && count != 1) return true;
                j = nextIndex;
                ++count;
            }
        }
        return false;
    }
};