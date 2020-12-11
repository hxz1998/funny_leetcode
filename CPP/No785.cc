/**
 * Created by Xiaozhong on 2020/12/11.
 * Copyright (c) 2020/12/11 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        const int UNCOLOR = 0;
        const int RED = 1;
        const int BLUE = 2;

        vector<int> colors(graph.size(), UNCOLOR);
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == UNCOLOR) {
                queue<int> q;
                q.push(i);
                colors[i] = RED;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int color = (colors[node] == RED ? BLUE : RED);
                    for (auto item : graph[node]) {
                        if (colors[item] == UNCOLOR) {
                            colors[item] = color;
                            q.push(item);
                        } else if (colors[item] != color) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {
            {1, 3},
            {0, 2},
            {1, 3},
            {0, 2}
    };
    cout << s.isBipartite(graph) << endl;
}