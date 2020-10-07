/**
 * Created by Xiaozhong on 2020/9/14.
 * Copyright (c) 2020/9/14 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int helper(vector<int> &stones, int index, int jumpsize, vector<vector<int>> memo) {
        if (memo[index][jumpsize] >= 0) return memo[index][jumpsize];
        for (int i = index + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[index];
            if (gap >= jumpsize - 1 && gap <= jumpsize + 1) {
                if (helper(stones, i, gap, memo) == 1) {
                    memo[index][gap] = 1;
                    return 1;
                }
            }
        }
        memo[index][jumpsize] = (index == stones.size() - 1) ? 1 : 0;
        return memo[index][jumpsize];
    }

public:
    bool canCross(vector<int> &stones) {
        vector<vector<int>> memo(stones.size(), vector<int>(stones.size(), -1));
        return helper(stones, 0, 0, memo) == 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << s.canCross(nums) << endl;
    nums = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << s.canCross(nums);
}