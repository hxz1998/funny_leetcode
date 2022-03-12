/**
 * Created by Xiaozhong on 2022/3/12.
 * Copyright (c) 2022/3/12 Xiaozhong. All rights reserved.
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

using namespace std;

// 优先级队列也可以的
int main() {
    unordered_set<int> uSet;
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    vector<vector<int>> rec(n);
    for (int idx = 0; idx < n; ++idx) {
        int first = 0, second = 0;
        cin >> first;
        cin >> second;
        rec[idx] = {first, second};
        cnt[first]++;
        cnt[second]++;
    }
    vector<pair<int, vector<int>>> conflict;
    for (const vector<int> &item: rec) {
        conflict.emplace_back(make_pair(cnt[item[0]] - 1 + cnt[item[1]] - 1, item));
    }
    sort(conflict.begin(), conflict.end(), [](const pair<int, vector<int>> &lhs, const pair<int, vector<int>> &rhs) {
        return lhs.first < rhs.first;
    });
    vector<bool> used(m + 1);
    int ans = 0;
    for (int idx = 0; idx < n; ++idx) {
        auto item = conflict[idx];
        int first = item.second[0];
        int second = item.second[1];
        if (!used[first] && !used[second]) {
            ans++;
            used[first] = true;
            used[second] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
