/**
 * Created by Xiaozhong on 2020/9/20.
 * Copyright (c) 2020/9/20 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2) {
            return v1[1] < v2[1];
        });
        int count = 1, x_end = intervals[0][1];
        for (vector<int> item: intervals) {
            int start = item[0];
            if (start >= x_end) {
                ++count;
                x_end = item[1];
            }
        }
        return intervals.size() - count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {
            {1, 2},
            {2, 3},
            {3, 4},
            {1, 3},
    };
    cout << s.eraseOverlapIntervals(intervals) << endl;
    intervals = {
            {1, 2},
            {1, 2},
            {1, 2}
    };
    cout << s.eraseOverlapIntervals(intervals) << endl;
}