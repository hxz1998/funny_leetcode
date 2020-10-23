/**
 * Created by Xiaozhong on 2020/10/23.
 * Copyright (c) 2020/10/23 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    double distance(const vector<int> &p1, const vector<int> &p2) {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end());
        return ((distance(points[0], points[3]) == distance(points[1], points[2])) &&
                distance(points[0], points[1]) == distance(points[1], points[3]) &&
                distance(points[1], points[3]) == distance(points[3], points[2]) &&
                distance(points[3], points[2]) == distance(points[2], points[0]) &&
                distance(points[0], points[1]) != 0
        );
    }
};

int main() {
    Solution s;
    vector<int> p1 = {0, 0}, p2 = {1, 1}, p3 = {1, 0}, p4 = {0, 1};
    cout << s.validSquare(p1, p2, p3, p4) << endl;

}