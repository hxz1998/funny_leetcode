/**
 * Created by Xiaozhong on 2020/10/2.
 * Copyright (c) 2020/10/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int helper(const vector<int> &nums, int start, int end, int turn) {
        // 如果 start == end，那么说明已经到了最后一个元素，直接返回去就好了
        // turn 为 1 表示我拿， -1 表示他拿
        if (start == end) {
            return nums[start] * turn;
        }
        // 记录得分，首先记录先拿第一个能得到的分
        int scoreStart = nums[start] * turn + helper(nums, start + 1, end, -turn);
        // 再记录第二个去拿的时候能得到的分
        int endStart = nums[end] * turn + helper(nums, start, end - 1, -turn);
        // 综合起来看看，拿第一个好呢，还是第二个好
        return max(scoreStart * turn, endStart * turn) * turn;
    }

public:
    bool PredictTheWinner(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1, 1) >= 0;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 233, 7};
    cout << s.PredictTheWinner(nums) << endl;
}