/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    int myRob(vector<int> &nums, int start, int end) {
        int pre = 0, cur = 0, tmp;
        for (int i = start; i < end; i++) {
            tmp = cur;
            cur = max(cur, pre + nums[i]);
            pre = tmp;
        }
        return cur;
    }

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        return max(myRob(nums, 0, nums.size() - 1),
                   myRob(nums, 1, nums.size()));
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.rob(nums) << endl;
}