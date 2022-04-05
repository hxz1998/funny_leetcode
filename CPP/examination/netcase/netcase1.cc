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

const static vector<vector<int>> dirs = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};
const static vector<char> chars = {'1', '2', '3'};

bool check(const vector<string> &board, const vector<vector<vector<int>>> &area) {
    // 检查行
    for (int row = 0; row < 3; ++row) {
        unordered_set<char> visited;
        for (int col = 0; col < 3; ++col) {
            visited.insert(board[row][col]);
        }
        if (visited.size() != 3) return false;
    }
    // 检查列
    for (int col = 0; col < 3; ++col) {
        unordered_set<char> visited;
        for (int row = 0; row < 3; ++row) visited.insert(board[row][col]);
        if (visited.size() != 3) return false;
    }
    // 检查区域
    for (const vector<vector<int>> &item: area) {
        unordered_set<char> visited;
        for (const vector<int> &xy: item) visited.insert(board[xy[0]][xy[1]]);
        if (visited.size() != 3) return false;
    }
    return true;
}

void dfs(vector<string> &board, const vector<vector<vector<int>>> &area,
         vector<bool> &visited,
         const vector<vector<int>> &target,
         int num,       // 目前格子上已经确定了多少个点了
         int from,
         vector<vector<string>> &ans) {
    for (int idx = 0; idx < 3; ++idx) {
        board[target[from][0]][target[from][1]] = chars[idx];
        visited[from] = true;
        num--;
        if (num == 0 && check(board, area)) ans.push_back(board);
        else {
            for (int next = 0; next < target.size(); ++next) {
                if (!visited[next])
                    dfs(board, area, visited, target, num, next, ans);
            }
        }
        num++;
        visited[from] = false;
        board[target[from][0]][target[from][1]] = '*';
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
        vector<vector<int>> target;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == '*') {
                    num++;
                    target.push_back({row, col});
                }
            }
        }
        vector<vector<string>> ans;
        vector<bool> visited(target.size());

        for (int next = 0; next < target.size(); ++next)
            dfs(board, area, visited, target, num, next, ans);

        if (ans.size() > 1) cout << "Multiple";
        else if (ans.empty()) cout << "No";
        else {
            for (int row = 0; row < 3; ++row) {
                cout << ans[0][row] << endl;
            }
        }
    }
}