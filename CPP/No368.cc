/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "unordered_map"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> _eds;
    vector<int> _nums;

    // 查找以 i 为结尾的最长子序列
    vector<int> eds(int i) {
        // 如果之前计算过了，那就没必要再计算了
        if (_eds.count(i)) return _eds[i];
        vector<int> max_subset;
        // 从 k 到 i 逐个计算最大子序列
        for (int k = 0; k < i; ++k) {
            if (_nums[i] % _nums[k] == 0) { // 如果最大值可以被 k 位置上的数整除，那么就继续下一步
                vector<int> subset = eds(k);
                if (max_subset.size() < subset.size()) max_subset = subset;
            }
        }

        vector<int> entry(max_subset.begin(), max_subset.end());
        entry.push_back(_nums[i]); // 添加进来现在的数
        _eds[i] = entry; // 建立记忆
        return entry;
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        this->_nums = nums;

        vector<int> max_subset;
        for (int i = 0; i < n; ++i) {
            vector<int> subset = eds(i);
            if (max_subset.size() < subset.size()) max_subset = subset;
        }
        return max_subset;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<int> ans = s.largestDivisibleSubset(nums);
    for (int i : ans) cout << i << " ";
}