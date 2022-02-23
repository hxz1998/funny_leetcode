/*
 * Created by Xiaozhong on 2/23/2022.
 * Copyright (c) 2/23/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        vector<vector<int>> ans;
        for (const vector<int> &interval: intervals) {
            if (ans.empty()) ans.emplace_back(interval);
            vector<int> prev = ans.back();
            ans.pop_back();
            if (interval[0] > prev[1]) {
                ans.emplace_back(prev);
                ans.emplace_back(interval);
            } else {
                vector<int> next = {prev[0], max(prev[1], interval[1])};
                ans.emplace_back(next);
            }
        }
        return ans;
    }
};

ostream &operator<<(ostream &os, const vector<vector<int>> &data) {
    for (const vector<int> &item: data) {
        for (int num: item) os << num << ", ";
        os << endl << flush;
    }
    return os;
}

int main() {
    Solution s;
    vector<vector<int>> intervals = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}};
    cout << s.merge(intervals) << endl;
}