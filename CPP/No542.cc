/**
 * Created by Xiaozhong on 2020/10/15.
 * Copyright (c) 2020/10/15 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix.front().size();
        queue<vector<int>> q;
        // 先把 0 们入队，把 1 标记成 -1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = -1;
                } else {
                    q.push(vector<int>{i, j});
                }
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
        // 对每一个队列里面的元素进行四周检查， 如果是 -1 则将 + 1
        while (!q.empty()) {
            vector<int> point = q.front();
            q.pop();
            int x = point.front(), y = point.back();
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n
                    && matrix[newX][newY] == -1) {
                    matrix[newX][newY] = matrix[x][y] + 1;
                    // 当然，还需要把改变后的元素也记录一下
                    q.push(vector<int>{newX, newY});
                }
            }
        }
        return matrix;
    }
};