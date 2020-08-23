/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> ans;
        if (nums.empty()) return ans;
        int candidate_1 = nums[0], count_1 = 0;
        int candidate_2 = nums[0], count_2 = 0;

        for (int num : nums) {
            // 投票阶段，如果当前数与投票员一致，那么就++
            if (candidate_1 == num) {
                count_1++;
                continue;
            }
            if (candidate_2 == num) {
                count_2++;
                continue;
            }

            // 更换投票对象，说明一个人的票数被抵消至 0
            if (count_1 == 0) {
                candidate_1 = num;
                count_1++;
                continue;
            }
            if (count_2 == 0) {
                candidate_2 = num;
                count_2++;
                continue;
            }

            // 相互抵消阶段
            count_1--;
            count_2--;
        }

        // 计数阶段
        count_1 = 0;
        count_2 = 0;
        for (int num : nums) {
            if (num == candidate_1) count_1++;
            else if (num == candidate_2) count_2++;
        }
        // 检查是否超过 N / 3，如果超过那么就将其添加进结果集
        if (count_1 > nums.size() / 3) ans.push_back(candidate_1);
        if (count_2 > nums.size() / 3) ans.push_back(candidate_2);
        return ans;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution s;
    vector<int> ans = s.majorityElement(nums);
    for (int i : ans) {
        cout << i << " ";
    }
}