/**
 * Created by Xiaozhong on 2020/7/28.
 * Copyright (c) 2020/7/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        // m_ptr 指向待修改的位置，s_ptr 指向扫描的位置，count 负责记录出现的次数
        int m_ptr = 1, count = 1;
        for (int s_ptr = 1; s_ptr < nums.size(); s_ptr++) {
            if (nums[s_ptr] == nums[s_ptr - 1]) count++;
            else count = 1;
            if (count <= 2) nums[m_ptr++] = nums[s_ptr];
        }
        return m_ptr;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution s;
    int length = s.removeDuplicates(nums);
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
}