/**
 * Created by Xiaozhong on 2022/3/30.
 * Copyright (c) 2022/3/30 Xiaozhong. All rights reserved.
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
private:
    struct cmp {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first > rhs.first;
        }
    };

public:
    static vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> available;
        for (int no = 0; no < k; ++no) available.insert(no);
        // 存储数据格式为 {服务器结束时间, 服务器编号}
        // 首先按照结束时间从小到大排序，然后按照服务器编号从小到大排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> busy;

        vector<int> cnt(k);
        int n = static_cast<int>(arrival.size());
        for (int idx = 0; idx < n; ++idx) {
            while (!busy.empty() && busy.top().first <= arrival[idx]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) continue;
            auto p = available.lower_bound(idx % k);
            if (p == available.end()) p = available.begin();
            cnt[*p]++;
            busy.push({arrival[idx] + load[idx], *p});
            available.erase(*p);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int idx = 0; idx < cnt.size(); ++idx) if (cnt[idx] == mx) ans.push_back(idx);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};
    s.busiestServers(3, arrival, load);
}