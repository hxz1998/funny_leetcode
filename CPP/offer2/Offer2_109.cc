/**
 * Created by Xiaozhong on 2022/4/2.
 * Copyright (c) 2022/4/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000") return 0;
        unordered_set < string > dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end()) return -1;
        auto prev = [](char c) {
            return (c == '0' ? '9' : c - 1);
        };
        auto next = [](char c) {
            return (c == '9' ? '0' : c + 1);
        };
        auto get = [&](string &status) {
            vector<string> ret;
            for (int i = 0; i < 4; ++i) {
                char c = status[i];
                status[i] = next(c);
                ret.push_back(status);
                status[i] = prev(c);
                ret.push_back(status);
                status[i] = c;
            }
            return ret;
        };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set < string > seen{"0000"};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto[status, steps] = q.front();
                q.pop();
                for (auto &&next_status: get(status)) {
                    if (seen.find(next_status) == seen.end() && dead.find(next_status) == dead.end()) {
                        if (next_status == target) return steps + 1;
                        q.emplace(next_status, steps + 1);
                        seen.insert(move(next_status));
                    }
                }
            }
        }
        return -1;
    }
};