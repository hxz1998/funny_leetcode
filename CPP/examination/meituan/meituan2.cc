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

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int idx = 0; idx < n; ++idx) cin >> nums[idx];
    vector<int> negCnt(n + 1);
    for (int idx = 0; idx < n; ++idx) {
        negCnt[idx + 1] = negCnt[idx] + (nums[idx] == -1 ? 1 : 0);
    }
    int ans = 0;
    for (int begin = 0; begin < n; ++begin) {
        for (int end = begin; end < n; ++end) {
            int num = negCnt[end + 1] - negCnt[begin];
            if (num % 2 == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}