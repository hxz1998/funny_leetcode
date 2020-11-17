/**
 * Created by Xiaozhong on 2020/11/16.
 * Copyright (c) 2020/11/16 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> adjacent;

    bool check(const int from, const int prev, const int to) {
        if (from == to) return true;
        auto dists = adjacent[from];
        for (auto dist : dists) {
            if (dist == prev) continue;
            if (check(dist, from, to)) return true;
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        for (const auto &edge : edges) {
            bool res = check(edge.front(), 0, edge.back());
            if (res) return edge;
            else {
                int from = edge.front(), to = edge.back();
                adjacent[from].insert(to);
                adjacent[to].insert(from);
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {
            {1, 2},
            {1, 3},
            {2, 3}
    };
    vector<int> ans = s.findRedundantConnection(edges);
    return 0;
}