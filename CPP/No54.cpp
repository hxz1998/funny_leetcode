/**
 * Created by Xiaozhong on 2020/7/20.
 * Copyright (c) 2020/7/20 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int top = 0;
        int bottom = (int) matrix.size() - 1;
        int left = 0;
        int right = (int) matrix[0].size() - 1;

        while (true) {
            // 从左到右
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            if (++top > bottom) break; // 右上角转角判断
            // 从上到下
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            if (--right < left) break; // 右下角转角判断
            // 从右到左
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) break; // 左下角转角判断
            // 从下到上
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            if (++left > right) break; // 左上角转角判断
        }

        return ans;
    }
};

int main(int argc, char *args[]) {
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    Solution s;
    vector<int> ans = s.spiralOrder(matrix);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}