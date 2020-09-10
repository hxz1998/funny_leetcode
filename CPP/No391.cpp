/**
 * Created by Xiaozhong on 2020/9/10.
 * Copyright (c) 2020/9/10 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "map"

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        // 保存四个最大外围点
        int left = INT32_MAX, right = INT32_MIN;
        int bottom = INT32_MAX, top = INT32_MIN;
        // 保存最大的面积
        int s = 0;
        // 保存每一个点 {x, y} 出现的次数
        map<pair<int, int>, int> mapper;

        // 挨个检查,对面积进行累加, 对点进行计数
        for (const vector<int> &v : rectangles) {
            left = min(left, v[0]);
            right = max(right, v[2]);
            bottom = min(bottom, v[1]);
            top = max(top, v[3]);

            s += (v[2] - v[0]) * (v[3] - v[1]);
            mapper[{v[0], v[1]}]++;
            mapper[{v[0], v[3]}]++;
            mapper[{v[2], v[1]}]++;
            mapper[{v[2], v[3]}]++;
        }
        // 如果最大面积和当前实际面积不同, 那么就直接返回 false
        if (s != (right - left) * (top - bottom)) return false;
        // 把四个角的点加成偶数, 这个时候每一个点的计数都应该是 2 或者 4
        mapper[{left, bottom}]++;
        mapper[{left, top}]++;
        mapper[{right, bottom}]++;
        mapper[{right, top}]++;
        // 判断有没有奇数,如果有奇数,那么就说明没完全拼成
        for (auto it = mapper.begin(); it != mapper.end(); it++) {
            if (it->second & 1) return false;
        }
        return true;
    }
};