/**
 * Created by Xiaozhong on 2020/10/3.
 * Copyright (c) 2020/10/3 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <random>

using namespace std;

class Solution {
public:
    vector<vector<int>> rects;
    vector<int> psum;
    int tot = 0;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<vector<int>> rects) {
        this->rects = rects;
        for (auto &x : rects) {
            tot += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            psum.push_back(tot);
        }
        uni = uniform_int_distribution < int > {0, tot - 1};
    }

    vector<int> pick() {
        int targ = uni(rng);

        int lo = 0;
        int hi = rects.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }

        auto &x = rects[lo];
        int width = x[2] - x[0] + 1;
        int height = x[3] - x[1] + 1;
        int base = psum[lo] - width * height;
        return {x[0] + (targ - base) % width, x[1] + (targ - base) / width};
    }
};