/**
 * Created by Xiaozhong on 2020/10/16.
 * Copyright (c) 2020/10/16 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &M, vector<int> &visited, int start) {
        for (int i = 0; i < M.size(); ++i) {
            if (M[start][i] == 1 && visited[i] != 1) {
                visited[i] = 1;
                dfs(M, visited, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &M) {
        vector<int> visited(M.size(), 0);
        int ans = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                ++ans;
            }
        }
        return ans;
    }
};