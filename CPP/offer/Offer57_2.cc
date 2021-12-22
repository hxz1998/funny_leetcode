/*
 * Created by Xiaozhong on 12/18/2021.
 * Copyright (c) 12/18/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int left = 1, right = target - 1;
        while (left < right) {
            int res = (left + right) * (right - left + 1);
            if (res == 2 * target) ans.emplace_back(build(left, right));
            else if (res < 2 * target) left++;
            else right--;
        }
        return ans;
    }

private:
    vector<int> build(const int left, const int right) {
        vector<int> ret;
        for (int i = left; i <= right; ++i) ret.emplace_back(i);
        return ret;
    }
};

int main() {
    Solution s;
    s.findContinuousSequence(9);
}