/**
 * Created by Xiaozhong on 2020/12/14.
 * Copyright (c) 2020/12/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<vector<int>> graph(n, vector<int>(n));
        for (const vector<int> &flight : flights) {
            graph[flight[0]][flight[1]] = flight[2];
        }
        unordered_map<int, int> best;
        struct cmp {
            bool operator()(const vector<int> &lhs, const vector<int> &rhs) {
                return lhs.front() < rhs.front();
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push({0, 0, src});
        while (!pq.empty()) {
            vector<int> info = pq.top();
            pq.pop();
            int cost = info[0], k = info[1], place = info[2];
            if (k > K + 1 || cost > best.count(k * 1000 + place) ? best[k * 1000 + place] : INT32_MAX) continue;
            if (place == dst) return cost;
            for (int nei = 0; nei < n; ++nei)
                if (graph[place][nei] > 0) {
                    int newcost = cost + graph[place][nei];
                    if (newcost < best.count((k + 1) * 1000 + nei) ? best[(k + 1) * 1000 + nei] : INT32_MAX) {
                        pq.push({newcost, k + 1, nei});
                        best[(k + 1) * 1000 + nei] = newcost;
                    }
                }
        }
        return -1;
    }
};