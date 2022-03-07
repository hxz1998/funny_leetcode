/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        vector<vector<int>> ans;
        for (const vector<int> &item: people) {
            ans.insert(ans.begin() + item[1], item);
        }
        return ans;
    }
};