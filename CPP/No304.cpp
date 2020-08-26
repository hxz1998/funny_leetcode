/**
 * Created by Xiaozhong on 2020/8/26.
 * Copyright (c) 2020/8/26 Xiaozhong. All rights reserved.
 */
#include "vector"

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        sum.resize(matrix.size(), vector<int>(matrix[0].size() + 1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sum[i][j + 1] = sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; i++) ans += sum[i][col2 + 1] - sum[i][col1];
        return ans;
    }
};