/**
 * Created by Xiaozhong on 2020/10/5.
 * Copyright (c) 2020/10/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        priority_queue<int> p;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> c;
        for (int i = 0; i < Capital.size(); ++i) {
            c.emplace(make_pair(Capital[i], Profits[i]));
        }
        for (int i = 0; i < k; ++i) {
            while (!c.empty() && c.top().first <= W) {
                p.emplace(c.top().second);
                c.pop();
            }
            if (p.empty()) break;
            W += p.top();
            p.pop();
        }
        return W;
    }
};