/**
 * Created by Xiaozhong on 2020/9/29.
 * Copyright (c) 2020/9/29 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> _nums;
    vector<int> _sum;
    int possibleSquareSide;

    bool dfs(int index) {
        // 如果当前已经使用完备选边长了，那么就检查最终结果是否符合要求
        if (index == _nums.size()) {
            return _sum[0] == _sum[1] && _sum[1] == _sum[2] && _sum[2] == _sum[3];
        }
        // 取出来备选边长
        int element = _nums[index];
        // 挨个在四个边中插入
        for (int i = 0; i < 4; ++i) {
            // 如果插入后，不会超过可能边长，那么就继续下面的检查
            if (_sum[i] + element <= possibleSquareSide) {
                _sum[i] += element; // 先加上去
                if (dfs(index + 1)) {
                    return true;
                }
                _sum[i] -= element; // 回溯！
            }
        }
        // 都不满足，返回false
        return false;
    }

public:
    Solution() { _sum = vector<int>(4, 0); }

    bool makesquare(vector<int> &nums) {
        // 先检查边界条件
        if (nums.empty() || nums.size() == 0 || nums.size() < 4) return false;
        int length = nums.size();
        _nums = move(nums);
        int perimeter = 0; // 记录周长
        for (int i = 0; i < length; ++i) perimeter += _nums[i];
        // 计算可能的边长长度
        possibleSquareSide = perimeter / 4;
        if (4 * possibleSquareSide != perimeter) return false; // 检查是否能整除
        // 递减序列排序，方便后面最优化计算
        sort(_nums.begin(), _nums.end(), [](const int &a, const int &b) {
            return a > b;
        });
        return dfs(0);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 2};
    cout << s.makesquare(nums) << endl;
    nums = {3, 3, 3, 3, 4};
    cout << s.makesquare(nums) << endl;
}