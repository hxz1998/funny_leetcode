/**
 * Created by Xiaozhong on 2020/8/30.
 * Copyright (c) 2020/8/30 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

/**
 * 输入：nums = [1,-2,-3,4]
 * 输出：4
 * 解释：数组本身乘积就是正数，值为 24 。
 */
class Solution {
public:
    int getMaxLen(vector<int> &nums) {
        int ans = 0;
        // 时间会超限，因为复杂度为 N ^ 2
        /*bool multi_num = true;
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            counter = 0;
            multi_num = true;
            for (int j = i; j < nums.size(); ++j) {
                counter++;
                if (nums[j] < 0) multi_num = !multi_num;
                if (nums[j] == 0) break;
                if (multi_num) ans = max(ans, counter);
            }
        }*/

        bool positive = true;
        int counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            counter++;
            if (nums[i] == 0) counter = 0;
            else if (nums[i] < 0) positive = !positive;
            if (positive) ans = max(ans, counter);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, -2, -3, 4};
    Solution s;
    cout << s.getMaxLen(nums) << endl;
    nums = {0, 1, -2, -3, -4};
    cout << s.getMaxLen(nums) << endl;
    nums = {-1, -2, -3, 0, 1};
    cout << s.getMaxLen(nums) << endl;
}