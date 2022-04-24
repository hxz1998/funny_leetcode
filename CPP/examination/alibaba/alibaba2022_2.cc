/**
 * Created by Xiaozhong on 2022/4/15.
 * Copyright (c) 2022/4/15 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

int main() {
    int target = 4;
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) cin >> board[i];
    // 0 代表横，1 代表竖， 2 代表斜对角
    vector<vector<vector<int>>> dpRed(n, vector<vector<int>>(m, vector<int>(3)));
    vector<vector<vector<int>>> dpPurple(n, vector<vector<int>>(m, vector<int>(3)));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            char color = board[x][y];
            if (color == '.') continue;
            else if (x == 0 && y == 0 && color == 'r') dpRed[x][y][0] = dpRed[x][y][1] = dpRed[x][y][2] = 1;
            else if (x == 0 && y == 0 && color == 'p') dpPurple[x][y][0] = dpPurple[x][y][1] = dpPurple[x][y][2] = 1;
            else if (x == 0 && color == 'r') {
                dpRed[x][y][0] = 1 + dpRed[x][y - 1][0];
                dpRed[x][y][2] = 1;
            } else if (x == 0 && color == 'p') {
                dpPurple[x][y][0] = 1 + dpPurple[x][y - 1][0];
                dpPurple[x][y][2] = 1;
            } else if (y == 0 && color == 'r') {
                dpRed[x][y][1] = dpRed[x - 1][y][1] + 1;
                dpRed[x][y][2] = 1;
            } else if (y == 0 && color == 'p') {
                dpPurple[x][y][1] = dpPurple[x - 1][y][1] + 1;
                dpPurple[x][y][2] = 1;
            } else {
                if (color == 'r') {
                    dpRed[x][y][0] = dpRed[x][y - 1][0] + 1;
                    dpRed[x][y][1] = dpRed[x - 1][y][1] + 1;
                    dpRed[x][y][2] = dpRed[x - 1][y - 1][2] + 1;
                } else if (color == 'p') {
                    dpPurple[x][y][0] = dpPurple[x][y - 1][0] + 1;
                    dpPurple[x][y][1] = dpPurple[x - 1][y][1] + 1;
                    dpPurple[x][y][2] = dpPurple[x - 1][y - 1][2] + 1;
                }
            }
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (dpRed[x][y][0] >= target || dpRed[x][y][1] >= target || dpRed[x][y][2] >= target) {
                cout << "kou" << endl;
                return 0;
            }
            if (dpPurple[x][y][0] >= target || dpPurple[x][y][1] >= target || dpPurple[x][y][2] >= target) {
                cout << "yukari" << endl;
                return 0;
            }
        }
    }
    cout << "to be continued" << endl;
    return 0;
}