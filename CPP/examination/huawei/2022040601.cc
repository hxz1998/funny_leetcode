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

int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>());
    int no = 0;
    for (int i = 0; i < N; ++i) {
        int T = 0;
        cin >> T;
        graph[no] = vector<int>(T);
        for (int j = 0; j < T; ++j)
            cin >> graph[no][j];
        no++;
    }
    vector<bool> visited(N);
    vector<int> path;
    int node = M;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        q.pop();
        for (int parent : graph[node]) {
            if (visited[parent]) {
                cout << -1 << endl;
                return 0;
            }
            path.push_back(parent);
            q.push(parent);
            visited[parent] = true;
        }
        node = q.front();
    }
    sort(path.begin(), path.end());
    for (int number : path) cout << number << " ";
    return 0;
}