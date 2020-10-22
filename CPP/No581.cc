/**
 * Created by Xiaozhong on 2020/10/22.
 * Copyright (c) 2020/10/22 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> copy_num = nums;
        sort(nums.begin(), nums.end());
        int start = nums.size(), end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (copy_num[i] != nums[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start > 0 ? (end - start + 1) : 0);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << s.findUnsortedSubarray(nums) << endl;
}