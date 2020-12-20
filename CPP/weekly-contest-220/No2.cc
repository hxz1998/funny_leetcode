/**
 * Created by Xiaozhong on 2020/12/20.
 * Copyright (c) 2020/12/20 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        // 左右指针，左指针负责把重复到的数及之前的数给吐出来
        // 右指针负责读入新的数，如果遇到重复的，那么就停下来更新左指针
        int left = 0, right = 0;
        unordered_set<int> bucket;
        int buf = 0;
        int ans = 0;
        while (left < nums.size()) {
            // 更新右指针，读入数据过程
            while (!bucket.count(nums[right])) {
                // 累加读到的不重复的新数据
                buf += nums[right];
                // 在集合中放入出现的数据
                bucket.insert(nums[right]);
                right++;
                // 如果右指针碰到了边界，那么就直接返回当前取到的最大值就好了
                if (right == nums.size()) {
                    ans = max(ans, buf);
                    return ans;
                }
            }
            // 遇到重复数，更新一下最大值
            ans = max(ans, buf);
            while (bucket.count(nums[right])) {
                bucket.erase(nums[left]);
                buf -= nums[left];
                left++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << s.maximumUniqueSubarray(nums) << endl;
    nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << s.maximumUniqueSubarray(nums) << endl;
}