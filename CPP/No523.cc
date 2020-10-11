/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int sum = 0;
        unordered_map<int, int> mapper;
        mapper[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) sum %= k;
            if (mapper.count(sum)) {
                if (i - mapper[sum] > 1) return true;
            } else {
                mapper[sum] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {23, 2, 4, 6, 7};
    cout << s.checkSubarraySum(nums, -6) << endl;
    nums = {0, 0};
    cout << s.checkSubarraySum(nums, 0) << endl;
    nums = {0};
    cout << s.checkSubarraySum(nums, 0) << endl;
}