/**
 * Created by Xiaozhong on 2020/9/15.
 * Copyright (c) 2020/9/15 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"
#include "list"

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &first, const vector<int> &second) {
            return first[0] == second[0] ? first[1] <= second[1] : first[0] > second[0];
        });

        int len = people.size();
        list<vector<int>> tmp;
        for (int i = 0; i < len; ++i) {
            auto pos = tmp.begin();
            advance(pos, people[i][1]); // 将迭代器 pos 前进 people[i][1] 个位置
            tmp.insert(pos, people[i]);
        }
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
