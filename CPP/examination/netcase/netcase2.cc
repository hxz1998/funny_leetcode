/**
 * Created by Xiaozhong on 2022/3/17.
 * Copyright (c) 2022/3/17 Xiaozhong. All rights reserved.
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


bool check(const vector<string> &board, const vector<vector<vector<int>>> &area, int x, int y, int num) {
    // 检查区域 x,y 能不能放下 num
    vector<vector<int>> no;
    for (const vector<vector<int>> &item: area) {
        for (const vector<int> &xy: item)
            if (xy[0] == x && xy[1] == y) {
                no = item;
            }
    }
    for (const vector<int> &xy: no)
        if (board[xy[0]][xy[1]] == ('0' + num))
            return false;
    return true;
}

void
dfs(vector<string> &board, const vector<vector<vector<int>>> &area,
    vector<vector<bool>> &line, vector<vector<bool>> &column,
    const vector<vector<int>> &target, vector<vector<string>> &ans, int start) {
    if (start == target.size()) {
        ans.push_back(board);
    } else {
        auto next = target[start];
        int x = next[0], y = next[1];
        for (int num = 1; num <= 3; ++num) {
            if (!line[x][num] && !column[y][num] && check(board, area, x, y, num)) {
                board[x][y] = static_cast<char>('0' + num);
                line[x][num] = true;
                column[y][num] = true;
                dfs(board, area, line, column, target, ans, start + 1);
                line[x][num] = false;
                column[y][num] = false;
                board[x][y] = '*';
            }
        }
    }
}

int main() {
    int T = 0;
    cin >> T;
    while (T-- > 0) {
        vector<string> board(3);
        for (int row = 0; row < 3; ++row) cin >> board[row];
        vector<vector<vector<int>>> area(3, vector<vector<int >>(3, vector<int>(2)));
        for (int areaNo = 0; areaNo <= 2; ++areaNo) {
            for (int idx = 0; idx < 3; ++idx) {
                cin >> area[areaNo][idx][0];
                cin >> area[areaNo][idx][1];
            }
        }
        int num = 0;
        vector<vector<bool>> line(3, vector<bool>(4));
        vector<vector<bool>> column(3, vector<bool>(4));
        vector<vector<int>> target;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == '*') {
                    num++;
                    target.push_back({row, col});
                } else {
                    int nu = board[row][col] - '0';
                    line[row][nu] = true;
                    column[col][nu] = true;
                }
            }
        }
        vector<vector<string>> ans;

        dfs(board, area, line, column, target, ans, 0);

        if (ans.size() > 1) cout << "Multiple";
        else if (ans.empty()) cout << "No";
        else {
            cout << "Unique" << endl;
            for (int row = 0; row < 3; ++row) {
                cout << ans[0][row] << endl;
            }
        }
        cout << endl;
    }
}
