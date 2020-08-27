/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp = nums;
        int n = nums.size();
        // 定位中间位置
        int mid = n & 1 ? n / 2 : (n / 2 - 1);
        for (int i = 0; i < nums.size(); i++) {
            // 根据奇偶来判断取哪一个值
            nums[i] = i & 1 ? temp[--n] : temp[mid--];
        }
    }
};

int main() {
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    Solution s;
    s.wiggleSort(nums);
    for (int i : nums) cout << i << " ";
}