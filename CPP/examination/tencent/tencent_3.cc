/**
 * Created by Xiaozhong on 2022/4/24.
 * Copyright (c) 2022/4/24 Xiaozhong. All rights reserved.
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
    int n = 0;
    cin >> n;
    string person;
    cin >> person;
    // 0代表进攻，1代表防守
    vector<vector<long long>> fightingCapacity(2, vector<long long>(n));
    for (int idx = 0; idx < n; ++idx) {
        if (idx == 0) {
            if (person[idx] == '0') fightingCapacity[0][0] = 1;
        } else {
            if (person[idx] == '0') fightingCapacity[0][idx] = fightingCapacity[0][idx - 1] + idx + 1;
            else fightingCapacity[0][idx] = fightingCapacity[0][idx - 1];
        }
    }
    for (int idx = n - 1; idx >= 0; --idx) {
        if (idx == n - 1) {
            if (person[idx] == '1') fightingCapacity[1][n - 1] = n;
        } else {
            if (person[idx] == '1') fightingCapacity[1][idx] = fightingCapacity[1][idx + 1] + idx + 1;
            else fightingCapacity[1][idx] = fightingCapacity[1][idx + 1];
        }
    }
    long long ans = INT32_MAX;
    for (int idx = 0; idx < n - 1; ++idx) {
        ans = min(ans, abs(fightingCapacity[0][idx] - fightingCapacity[1][idx + 1]));
    }
    ans = min(fightingCapacity[1][0], ans);
    ans = min(fightingCapacity[0][n - 1], ans);
    cout << ans;
}