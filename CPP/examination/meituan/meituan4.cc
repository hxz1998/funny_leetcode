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

int helper(const vector<vector<int>> &code, int start, int pointer, int sum, const int m) {
    if (start == code.size()) {
        return sum;
    }
    for (int next = 1; next <= m; ++next) {
        if (next == pointer) return helper(code, start + 1, next, sum, m);
        else return helper(code, start + 1, next, sum + 1, m);
    }
    return 0;
}

int main() {
    int n = 0, m = 0;
    cin >> n;
    cin >> m;
    vector<int> rooms(m);
    for (int idx = 0; idx < m; ++idx) {
        cin >> rooms[idx];
    }
    vector<vector<int>> code;
    int prev = rooms[0];
    int cnt = 1;
    for (int idx = 1; idx < m; ++idx) {
        if (prev == rooms[idx]) cnt++;
        else {
            code.push_back({prev, cnt});
            prev = rooms[idx];
            cnt = 1;
        }
    }
    code.push_back({prev, cnt});
    int ans = m;
    for (int pointer = 1; pointer <= m; ++pointer) {
        ans = min(ans, helper(code, 0, pointer, 0, m));
    }
    cout << ans << endl;
}