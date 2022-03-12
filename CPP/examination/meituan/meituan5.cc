/**
 * Created by Xiaozhong on 2022/3/12.
 * Copyright (c) 2022/3/12 Xiaozhong. All rights reserved.
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

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> mapper(n + 1);
    vector<int> color(n + 1);
    for (int idx = 1; idx <= n; ++idx) {
        cin >> color[idx];
    }
    for (int idx = 1; idx <= n; ++idx) {
        int node = 0;
        cin >> node;
        if (node == 0) continue;
        mapper[node].push_back(idx);
    }
    int white = 0, black = 0;
    for (int node = 1; node <= n; ++node) {
        // 黑色节点
        if (color[node] == 1) {
            if (mapper[node].empty()) black++;
            else {
                bool flag = true;
                for (int children: mapper[node]) {
                    if (color[children] == 1) {
                        flag = false;
                    }
                }
                if (flag) black++;
            }
        }
        // 白色节点
        if (color[node] == 0) {
            if (mapper[node].empty()) white++;
            else {
                for (int children: mapper[node]) {
                    if (color[children] == 1) {
                        white++;
                        break;
                    }
                }
            }
        }
    }
    cout << white << " " << black << endl;
    return 0;
}