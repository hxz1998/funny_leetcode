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
        for (int left = 1, right = 2; left < right; ) {
            int sum = (right + left) * (right - left + 1);
            if (sum == target * 2) {
                vector<int> buffer;
                for (int num = left; num <= right; ++num) buffer.emplace_back(num);
                ans.emplace_back(buffer);
                left++;
            } else if (sum < target * 2) right++;
            else left++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.findContinuousSequence(9);
}