/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<int> ans;
        bool visited[n];
        for (int i = 0; i < n; i++) { visited[i] = false; }
        for (vector<int> &item : edges) {
            if (!visited[item[1]]) visited[item[1]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    // n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
    Solution s;
    vector<vector<int>> edges = {
            {0, 1},
            {0, 2},
            {2, 5},
            {3, 4},
            {4, 2}
    };
    vector<int> ans = s.findSmallestSetOfVertices(6, edges);
    for (int i : ans) {
        cout << i << " ";
    }
}