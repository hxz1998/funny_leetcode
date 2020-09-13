/**
 * Created by Xiaozhong on 2020/9/13.
 * Copyright (c) 2020/9/13 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    bool check(vector<vector<int>> &mat, int rows, int cols, int i, int j) {
        for (int r = 0; r < rows; ++r) if (mat[r][j] == 1 && r != i) return false;
        for (int c = 0; c < cols; ++c) if (mat[i][c] == 1 && c != j) return false;
        return true;
    }

public:
    int numSpecial(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size(), count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    if (check(mat, rows, cols, i, j)) ++count;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> mat = {
            {1, 0, 0},
            {0, 0, 1},
            {1, 0, 0}
    };
    Solution s;
    cout << s.numSpecial(mat) << endl;
}