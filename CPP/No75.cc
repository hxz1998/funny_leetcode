/**
 * Created by Xiaozhong on 2020/7/24.
 * Copyright (c) 2020/7/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        // 三指针法，left 指向 0， right 指向 2， cur 指向当前
        int n = nums.size(), left = 0, right = n - 1, cur = 0;
        while (cur <= right) {
            if (nums[cur] == 0) swap(nums[cur++], nums[left++]);
            else if (nums[cur] == 2) swap(nums[cur], nums[right--]);
            else cur++;
        }
    }

private:
    void swap(int &i, int &j) {
        int tmp = i;
        i = j;
        j = tmp;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 0};
    s.sortColors(nums);
    for (int i : nums) {
        cout << i << " ";
    }
}