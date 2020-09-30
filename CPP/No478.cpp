/**
 * Created by Xiaozhong on 2020/9/30.
 * Copyright (c) 2020/9/30 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <random>

using namespace std;

class Solution {
private:
    double rad, xc, yc;
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};
public:
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    vector<double> randPoint() {
        double x0 = xc - rad;
        double y0 = yc - rad;
        while (true) {
            double xg = x0 + uni(rng) * 2 * rad;
            double yg = y0 + uni(rng) * 2 * rad;
            if (sqrt(pow(xg - xc, 2) + pow(yg - yc, 2)) <= rad) return {xg, yg};
        }
    }
};