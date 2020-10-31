/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) {
        // 排序，按照 x 轴进行单调排序
        sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs.front() < rhs.front();
        });
        int ans = 0;
        // 检查两个 x 轴之间最大间隔
        for (int i = 0; i < points.size() - 1; ++i) {
            ans = max(points[i + 1].front() - points[i].front(), ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {
            {8, 7},
            {9, 9},
            {7, 4},
            {9, 7}
    };
    cout << s.maxWidthOfVerticalArea(points) << endl;
}