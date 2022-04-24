/**
 * Created by Xiaozhong on 2022/4/6.
 * Copyright (c) 2022/4/6 Xiaozhong. All rights reserved.
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

class Solution {
private:
    const int RED = 1, BLUE = -1, GREY = 3;
    vector<int> colors;
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = static_cast<int>(graph.size());
        colors = vector<int>(n, GREY);
        colors[0] = BLUE;
        queue<int> q;
        for (int no = 0; no < n; ++no) {
            q.push(no);
            int color = RED;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                color = colors[node] == RED ? BLUE : RED;
                for (int next: graph[node]) {
                    if (colors[next] != GREY && colors[next] != color) return false;
                    if (colors[next] != GREY) continue;
                    colors[next] = color;
                    q.push(next);
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1},
                                 {0},
                                 {4},
                                 {4},
                                 {2, 3}};
    Solution s;
    cout << s.isBipartite(graph) << endl;
}