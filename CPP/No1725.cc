/**
 * Created by Xiaozhong on 2022/2/6.
 * Copyright (c) 2022/2/6 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        map<int, int, greater<int>> cnt;
        for (vector<int> rect: rectangles) {
            if (rect[0] > rect[1]) cnt[rect[1]]++;
            else cnt[rect[0]]++;
        }
        return cnt.begin()->second;
    }
};