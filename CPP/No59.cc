/**
 * Created by Xiaozhong on 2020/7/21.
 * Copyright (c) 2020/7/21 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 该题思路和第 54 题一猫猫一样~
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i].resize(n);
        }
        int right = n - 1, left = 0, top = 0, bottom = n - 1;
        int counter = 1;
        while (true) {
            for (int i = left; i <= right; ++i) ans[top][i] = counter++;
            if (++top > bottom) break;
            for (int i = top; i <= bottom; i++) ans[i][right] = counter++;
            if (--right < left) break;
            for (int i = right; i >= left; i--) ans[bottom][i] = counter++;
            if (--bottom < top) break;
            for (int i = bottom; i >= top; i--) ans[i][left] = counter++;
            if (++left > right) break;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.generateMatrix(3);
    for (vector<int> item : ans) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}