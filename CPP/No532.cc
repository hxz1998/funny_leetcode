/**
 * Created by Xiaozhong on 2020/10/13.
 * Copyright (c) 2020/10/13 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) return 0;
        // 使用集合来对结果进行统计，其中 visited 记录访问过的元素，
        // res 用来保存能够构成 k-diff 对中的较小值
        unordered_set<int> visited, res;
        for (int i : nums) {
            // 如果访问过的元素里面存在左值，那么就把较小值存进来
            if (visited.count(i - k)) res.insert(i - k);
            // 如果存在右值，就把自己存进来
            if (visited.count(i + k)) res.insert(i);
            visited.insert(i);
        }
        // 看看最后存了多少个
        return res.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << s.findPairs(nums, 2) << endl;
}