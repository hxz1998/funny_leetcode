/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int len = nums.size();

        unordered_map<int, int> mapper;
        mapper[0] = -1;
        int res = 0, pre_sum = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) pre_sum += 1;
            else pre_sum -= 1;

            if (mapper.count(pre_sum)) res = max(res, i - mapper[pre_sum]);
            else mapper[pre_sum] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0};
    cout << s.findMaxLength(nums) << endl;
}