/**
 * Created by Xiaozhong on 2022/4/16.
 * Copyright (c) 2022/4/16 Xiaozhong. All rights reserved.
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
    int ans = -1;

    bool check(const vector<int> &mt, const vector<vector<int>> &cb, int no) {
        for (int idx = 0; idx < static_cast<int>(mt.size()); ++idx) {
            if (mt[idx] < cb[no][idx]) return false;
        }
        return true;
    }

    void
    backtrack(vector<int> &mt, vector<vector<int>> &cb, vector<vector<int>> &attr, vector<bool> &visited,
              int limit, int at1, int li1, int start) {
        if (li1 >= limit) {
            ans = max(ans, at1);
        }
        for (int idx = 0; idx < static_cast<int>(cb.size()); ++idx) {
            if (!check(mt, cb, idx) || visited[idx]) continue;
            visited[idx] = true;
            for (int i = 0; i < static_cast<int>(mt.size()); ++i) mt[i] -= cb[idx][i];
            backtrack(mt, cb, attr, visited, limit, at1 + attr[idx][0], li1 + attr[idx][1], idx + 1);
            for (int i = 0; i < static_cast<int>(mt.size()); ++i) mt[i] += cb[idx][i];
            visited[idx] = false;
        }
    }

public:
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        // 遍历所有情况
        int n = static_cast<int>(cookbooks.size());
        vector<bool> visited(n, false);
        backtrack(materials, cookbooks, attribute, visited, limit, 0, 0, 0);
        return ans;
    }
};

int main() {
    vector<int> materials = {3, 2, 4, 1, 2};
    vector<vector<int>> cookbooks = {{1, 1, 0, 1, 2},
                                     {2, 1, 4, 0, 0},
                                     {3, 2, 4, 1, 0}};
    vector<vector<int>> attribute = {{3, 2},
                                     {2, 4},
                                     {7, 6}};
    Solution s;
    cout << s.perfectMenu(materials, cookbooks, attribute, 5);
}