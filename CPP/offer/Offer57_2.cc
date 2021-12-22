/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
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