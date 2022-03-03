/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
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
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> cnt;
        for (const char &task: tasks) cnt[task]++;

        vector<int> nextValid, rest;
        for (const pair<const char, int> &info: cnt) {
            nextValid.push_back(1);
            rest.push_back(info.second);
        }
        int m = (int) cnt.size();
        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            time++;
            int minNextValid = INT32_MAX;
            for (int j = 0; j < m; ++j) if (rest[j] > 0) minNextValid = min(minNextValid, nextValid[j]);

            time = max(time, minNextValid);
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] > 0 && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) best = j;
                }
            }
            nextValid[best] = time + n + 1;
            rest[best]--;
        }
        return time;
    }
};