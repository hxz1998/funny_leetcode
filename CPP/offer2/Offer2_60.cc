/**
 * Created by Xiaozhong on 2022/4/15.
 * Copyright (c) 2022/4/15 Xiaozhong. All rights reserved.
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
    struct cmp {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        for (int num: nums) cnt[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq(cnt.begin(), cnt.end());
        vector<int> ans;
        while (k-- > 0) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};