/**
 * Created by Xiaozhong on 2022/3/22.
 * Copyright (c) 2022/3/22 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>> &_matrix) {
        int n = static_cast<int>(_matrix.size()), m = static_cast<int>(_matrix[0].size());
        matrix = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (x == 0 && y == 0) matrix[x + 1][y + 1] = _matrix[x][y];
                else if (y == 0) matrix[x + 1][y + 1] = _matrix[x][y] + matrix[x][y + 1];
                else if (x == 0) matrix[x + 1][y + 1] = _matrix[x][y] + matrix[x + 1][y];
                else matrix[x + 1][y + 1] = matrix[x][y + 1] + matrix[x + 1][y] + _matrix[x][y] - matrix[x][y];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix[row2 + 1][col2 + 1] - matrix[row2 + 1][col1] - matrix[row1][col2 + 1] + matrix[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3);
}