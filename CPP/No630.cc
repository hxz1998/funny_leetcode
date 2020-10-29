/**
 * Created by Xiaozhong on 2020/10/30.
 * Copyright (c) 2020/10/30 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        auto compare = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs.back() < rhs.back();
        };
        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> pq;
        int day = 0;
        for (int i = 0; i < courses.size(); ++i) {
            if (day + courses[i][0] <= courses[i][1]) {
                pq.push(courses[i][0]);
                day += courses[i][0];
            } else {
                pq.push(courses[i][0]);
                day += courses[i][0];

                int max_duration = pq.top();
                day -= max_duration;
                pq.pop();
            }
        }
        return pq.size();
    }
};

