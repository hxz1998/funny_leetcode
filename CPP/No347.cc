/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"
#include "queue"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mapper;
        for (int i : nums) mapper[i]++; // 对每一个出现的元素都记录频率
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //创建优先级队列
        for (auto item : mapper) {
            if (pq.size() == k) {   // 如果队列满了，那么就把顶部元素弹出来，然后压入新的
                if (item.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(item.second, item.first));
                }
            } else {
                // 队列是不满的，那么就直接压入
                pq.push(make_pair(item.second, item.first));
            }
        }
        vector<int> ans;
        while (!pq.empty()) {   // 构造返回值
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};