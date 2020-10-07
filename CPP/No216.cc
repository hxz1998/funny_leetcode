/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

// 使用回溯法
class Solution {
private:
    vector<vector<int>> ans;    // 记录最后的答案
    vector<int> path;           // 记录路过的路径

    void dfs(int k, int start, int sum) {
        // 找到了一个符合要求的结果，添加进结果集
        if (k == 0 && sum == 0) {
            ans.push_back(path);
            return;
        }
        // 不满足要求，可用数已经为 0 了，但是总和 sum 还没有凑够
        if (k == 0 || sum < 0) return;
        // 从起始位置 start，逐个检查剩余元素添加进来后是否符合要求，最后再吐出去
        for (int i = start; i <= 9; i++) {
            path.push_back(i);  // 添加进来
            dfs(k - 1, i + 1, sum - i);
            path.pop_back();    // 吐出来
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, 1, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.combinationSum3(3, 9);
    for (vector<int> item : ans) {
        for (int i : item)
            cout << i << " ";
        cout << endl;
    }
}