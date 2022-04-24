/**
 * Created by Xiaozhong on 2022/4/19.
 * Copyright (c) 2022/4/19 Xiaozhong. All rights reserved.
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

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> tasks(n);
    vector<int> queries(m);
    for (int idx = 0; idx < n; ++idx) cin >> tasks[idx];
    for (int idx = 0; idx < m; ++idx) cin >> queries[idx];
    vector<int> prev(n);
    for (int idx = 0; idx < n; ++idx) {
        if (idx == 0) prev[idx] = tasks[idx];
        else prev[idx] = prev[idx - 1] + tasks[idx];
    }
    for (int query: queries) {
        auto pos = upper_bound(prev.begin(), prev.end(), query);
        cout << (pos - prev.begin()) << endl;
    }
}