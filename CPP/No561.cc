/**
 * Created by Xiaozhong on 2020/10/19.
 * Copyright (c) 2020/10/19 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i = i + 2) sum += nums[i];
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 4, 3, 2};
    cout << s.arrayPairSum(nums) << endl;
}