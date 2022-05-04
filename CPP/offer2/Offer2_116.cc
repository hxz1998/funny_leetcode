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
    public:
        UnionFind(int _n) : n(_n), parents(vector<int>(_n + 1)) {
            for (int idx = 0; idx <= n; ++idx) {
                parents[idx] = idx;
            }
        }

        void connect(int v, int o) {
            if (connected(v, o)) return;
            int v_parent = find(v);
            int o_parent = find(o);
            parents[o_parent] = v_parent;
            n--;
        }

        int find(int v) {
            if (v != parents[v]) {
                parents[v] = find(parents[v]);
            }
            return parents[v];
        }

        bool connected(int v, int o) {
            int v_parent = find(v);
            int o_parent = find(o);
            return v_parent == o_parent;
        }

        int size() const {
            return n;
        }

    private:
        int n = 0;
        vector<int> parents;
    };

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = static_cast<int>(isConnected.size());
        UnionFind unionFind(n);
        for (int o = 0; o < n; ++o) {
            for (int v = 0; v < n; ++v) {
                if (isConnected[o][v]) unionFind.connect(v, o);
            }
        }
        return unionFind.size();
    }
};