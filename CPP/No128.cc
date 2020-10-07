/**
 * Created by Xiaozhong on 2020/8/8.
 * Copyright (c) 2020/8/8 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> nums_set;
        // 首先对每一个数在集合中建立映射
        for (int i : nums) nums_set.insert(i);
        // 最长的连续序列初始化为 0
        int longest_streak = 0;
        // 挨个检查数值
        for (int num : nums_set) {
            // 如果不存在 num - 1，那就检查后面的 num + 1，num + 2， num + 3......
            if (!nums_set.count(num - 1)) {
                int current_streak = 1;
                int current_num = num;
                while (nums_set.count(++current_num)) current_streak++;
                // 并更新最长的序列
                longest_streak = max(current_streak, longest_streak);
            }
        }
        return longest_streak;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    cout << s.longestConsecutive(nums);
}