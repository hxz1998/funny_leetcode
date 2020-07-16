/**
 * Created by Xiaozhong on 2020/7/16.
 * Copyright (c) 2020/7/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        findAns(candidates, target, 0);
        return ansSet;
    }

private:
    // 最终符合要求的答案
    vector<vector<int>> ansSet;
    // 缓冲区
    vector<int> oneAns;

    void findAns(vector<int> &candidates, int target, int startIndex) {
        // 递归的结束点，把已满足要求的组合添加进列表
        if (target == 0) {
            ansSet.push_back(oneAns);
            return;
        }
        // 剪枝操作，把已经不符合要求的选项剔除，不再参与下面运算
        if (target < 0) return;
        // 之所以从 startIndex 开始，是因为要排除掉重复项，不能使用 2 2 3 和 3 2 2 这样的重复结果。
        for (int i = startIndex; i < candidates.size(); i++) {
            if (target >= 0) {
                // 如果大于零，那么就把当前参与运算的值放到缓冲区 oneAns 中来
                oneAns.push_back(candidates[i]);
                // 递归运算
                findAns(candidates, target - candidates[i], i);
                // 最后再把缓冲区加进来的值进行清空
                oneAns.pop_back();
            } else {
                break;
            }
        }
    }


};

int main(int argc, char *args[]) {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> ans = s.combinationSum(candidates, 7);
    for (int i = 0; i < ans.size(); i++) {
        for (int item:ans[i]) {
            cout << item << " - ";
        }
        cout << endl;
    }
}