/**
 * Created by Xiaozhong on 2020/9/23.
 * Copyright (c) 2020/9/23 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
private:
    int distance(const vector<int> &first, const vector<int> &second) {
        return (first[0] - second[0]) * (first[0] - second[0]) + (first[1] - second[1]) * (first[1] - second[1]);
    }

public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> mapper;
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    int d = distance(points[i], points[j]);
                    if (mapper.count(d)) ++mapper[d];
                    else mapper[d] = 1;
                }
            }
            for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
                if (iter->second >= 2) ans += iter->second * (iter->second - 1);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {
            {0, 0},
            {1, 0},
            {2, 0}
    };
    Solution s;
    cout << s.numberOfBoomerangs(points);
}