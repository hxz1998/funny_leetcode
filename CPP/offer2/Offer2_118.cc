/**
 * Created by Xiaozhong on 2022/4/29.
 * Copyright (c) 2022/4/29 Xiaozhong. All rights reserved.
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
    class UnionFind {
    private:
        int find(int v) {
            if (v != parents[v]) {
                parents[v] = find(parents[v]);
            }
            return parents[v];
        }

    public:
        UnionFind(int size) : parents(vector<int>(size + 1)) {
            for (int idx = 0; idx <= size; ++idx) parents[idx] = idx;
        }

        bool connected(int lhs, int rhs) {
            int lhs_parent = find(lhs);
            int rhs_parent = find(rhs);
            return lhs_parent == rhs_parent;
        }

        // 右边连接到左边
        void connect(int lhs, int rhs) {
            int lhs_parent = find(lhs);
            int rhs_parent = find(rhs);
            if (lhs_parent == rhs_parent) return;
            parents[rhs_parent] = lhs_parent;
        }

    private:
        vector<int> parents;
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> ans;
        int n = static_cast<int>(edges.size());
        UnionFind unionFind(n);
        for (const vector<int> &edge: edges) {
            int lhs = edge[0], rhs = edge[1];
            if (unionFind.connected(lhs, rhs)) ans = edge;
            else unionFind.connect(lhs, rhs);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 4},
                                 {3, 4},
                                 {1, 3},
                                 {1, 2},
                                 {4, 5}};
    s.findRedundantConnection(edges);
}