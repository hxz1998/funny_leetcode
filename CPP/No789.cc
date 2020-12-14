/**
 * Created by Xiaozhong on 2020/12/14.
 * Copyright (c) 2020/12/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        for (const vector<int> &ghost : ghosts) {
            if (distance({0, 0}, target) >= distance(ghost, target)) return false;
        }
        return true;
    }

private:
    int distance(vector<int> src, const vector<int> &dst) {
        return abs(src[0] - dst[0]) + abs(src[1] - dst[1]);
    }
};