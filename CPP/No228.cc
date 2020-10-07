/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            // 如果 j 和 j + 1 仍然在 nums.size() 内，那么就看看它和下一个元素是否满足差值为 1，如果满足：
            // 那么就跳过这次，让 j 往后跳
            if (j + 1 < nums.size() && (nums[j + 1] == 1 + nums[j])) continue;
            // 该句是判断中间一个元素的字符串
            if (i == j) ans.push_back(to_string(nums[i]));
            // 将结果添加进结果集，也就是说碰到了分界线，而且不是单独一个元素的情况
            else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            // 更新 i 为 j 的下一个
            i = j + 1;
        }
        return ans;
    }
};

#include "iostream"

int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 8};
    Solution s;
    vector<string> ans = s.summaryRanges(nums);
    for (string item : ans) {
        cout << item << endl;
    }
}