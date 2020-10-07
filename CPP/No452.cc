/**
 * Created by Xiaozhong on 2020/9/25.
 * Copyright (c) 2020/9/25 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2) {
            return p1[1] < p2[1];
        });
        int arrows = 1, end = points[0][1];
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] > end) {
                end = points[i][1];
                ++arrows;
            }
        }
        return arrows;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums{
            {10, 16},
            {2,  8},
            {1,  6},
            {7,  12}
    };
    cout << s.findMinArrowShots(nums) << endl;
}
