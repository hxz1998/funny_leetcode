/**
 * Created by Xiaozhong on 2020/10/11.
 * Copyright (c) 2020/10/11 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    bool helper(const vector<int> &road, pair<int, int> &target) {
        if (road[0] == target.first && road[1] == target.first ||
            road[0] == target.first && road[1] == target.first)
            return true;
        return false;
    }

public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        int ans = 0;
        if (roads.empty()) return ans;
        unordered_map<int, int> mapper;
        for (vector<int> &road : roads) {
            ++mapper[road[0]];
            ++mapper[road[1]];
        }
        vector<pair<int, int>> counter;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            counter.emplace_back(make_pair(iter->first, iter->second));
        }
        sort(counter.begin(), counter.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        });
        pair<int, int> A, B;
        A = counter[0];
        B = counter[1];
        // 没做完~
        return counter[0].second + counter[1].second;
    }
};

int main() {
    Solution s;
    vector<vector<int>> roads = {
            {0, 1},
            {0, 3},
            {1, 2},
            {1, 3}
    };
    cout << s.maximalNetworkRank(4, roads) << endl;
    roads = {
            {0, 1},
            {0, 3},
            {1, 2},
            {1, 3},
            {2, 3},
            {2, 4}
    };
    cout << s.maximalNetworkRank(5, roads) << endl;

    roads = {
            {0, 1},
            {1, 2},
            {2, 3},
            {2, 4},
            {5, 6},
            {5, 7}
    };
    cout << s.maximalNetworkRank(8, roads) << endl;
}