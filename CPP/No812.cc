/**
 * Created by Xiaozhong on 2020/12/12.
 * Copyright (c) 2020/12/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    inline double S(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        return 0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] -
                         a[1] * b[0] - b[1] * c[0] - c[1] * a[0]);
    }

public:
    double largestTriangleArea(vector<vector<int>> &points) {
        double ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    ans = max(ans, S(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};