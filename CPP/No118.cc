/**
 * Created by Xiaozhong on 2020/8/6.
 * Copyright (c) 2020/8/6 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if (!numRows) return ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                // 动态转移方程
                if (j == 0 || j == i) {
                    ans[i].push_back(1);
                } else {
                    ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.generate(5);
    for (const vector<int>& item : ans) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}