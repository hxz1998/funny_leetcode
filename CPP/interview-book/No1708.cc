/**
 * Created by Xiaozhong on 2021/11/7.
 * Copyright (c) 2021/11/7 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int bestSeqAtIndex(vector<int> &height, vector<int> &weight) {
        int n = height.size();
        vector<vector<int>> person(n);
        for (int idx = 0; idx < height.size(); ++idx)
            person[idx] = vector<int>{height[idx], weight[idx]};
        sort(person.begin(), person.end(), [](const vector<int> &lhs, const vector<int> &rhs) -> bool {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        vector<int> dp;
        for (const vector<int> &item : person) {
            vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), item[1]);
            if (iter == dp.end()) dp.emplace_back(item[1]);
            else *iter = item[1];
        }
        return dp.size();
    }
};

ostream &operator<<(ostream &os, vector<vector<int>> &data) {
    for (vector<int> &item : data) {
        for (int num : item) os << num << " ";
        os << endl;
    }
    return os;
}

int main() {
    vector<vector<int>> nums = {{1, 4},
                                {1, 5},
                                {3, 5},
                                {2, 3}};
    sort(nums.begin(), nums.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
    });

    cout << nums << endl;
}