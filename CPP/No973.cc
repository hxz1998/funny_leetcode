/**
 * Created by Xiaozhong on 2020/11/9.
 * Copyright (c) 2020/11/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<pair<vector<int>, double>> mapper;
        for (const vector<int> &item : points) {
            // 计算和原点的距离，并且存起来
            mapper.emplace_back(make_pair(
                    item, sqrt(item.front() * item.front() + item.back() * item.back()))
            );
        }
        sort(mapper.begin(), mapper.end(),
             // 按照和原点的距离进行排序，从小到大
             [](const pair<vector<int>, double> &rhs, const pair<vector<int>, double> &lhs) {
                 return rhs.second < lhs.second;
             });
        vector<vector<int>> ans;
        for (int i = 0; i < K; ++i) ans.emplace_back(mapper[i].first);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {
            {3,  3},
            {5,  -1},
            {-2, 4}
    };
    vector<vector<int>> ans = s.kClosest(points, 2);
    return 0;
}