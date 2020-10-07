/**
 * Created by Xiaozhong on 2020/7/17.
 * Copyright (c) 2020/7/17 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, (int) nums.size());
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, vector<int> &output, int first, int len) {
        // 结束条件，所有的数都填充完了
        if (first == len) {
            ans.push_back(output);
            return;
        }
        // 从当前位置开始，向后开始检查
        for (int i = first; i < len; ++i) {
            // 将当前数归入左侧使用过的数中去
            swap(output[i], output[first]);
            // 递归检查，填充数据
            backtrack(ans, output, first + 1, len);
            // 恢复现场
            swap(output[i], output[first]);
        }
    }
};

int main(int argc, char *args[]) {
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for (vector<int> item : ans) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}