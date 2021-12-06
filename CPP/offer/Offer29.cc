/**
 * Created by Xiaozhong on 2021/12/5.
 * Copyright (c) 2021/12/5 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) return vector<int>();
        int n = matrix.size(), m = matrix[0].size();
        int sz = n * m;
        int x = 0, y = 0, turns = 1;
        vector<int> ans;
        while (ans.size() < sz - 1) {
            // 从左向右
            while (ans.size() < sz && y < m - turns) ans.emplace_back(matrix[x][y++]);
            while (ans.size() < sz && x < n - turns) ans.emplace_back(matrix[x++][y]);
            while (ans.size() < sz && y >= turns) ans.emplace_back(matrix[x][y--]);
            while (ans.size() < sz && x >= turns) ans.emplace_back(matrix[x--][y]);
            x = turns;
            y = turns;
            turns++;
        }
        if (ans.size() != sz && m % 2 == 1 && n % 2 == 1) ans.emplace_back(matrix[m / 2][n / 2]);
        return ans;
    }
};

int main() {
    /*vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};*/
    /*vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};*/
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
//    vector<vector<int>> matrix = {{1, 2, 3}};
    Solution s;
    s.spiralOrder(matrix);
}

