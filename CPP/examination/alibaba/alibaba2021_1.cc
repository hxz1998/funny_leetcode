/**
 * Created by Xiaozhong on 2022/4/10.
 * Copyright (c) 2022/4/10 Xiaozhong. All rights reserved.
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
    int T = 0;
    cin >> T;
    while (T-- > 0) {
        int n = 0;
        cin >> n;
        vector<vector<int>> data(n, vector<int>(2));
        for (int idx = 0; idx < n; ++idx) cin >> data[idx][0];
        for (int idx = 0; idx < n; ++idx) cin >> data[idx][1];
        sort(data.begin(), data.end(), [](const vector<int> &lhs, const vector<int> &rhs) -> bool {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        // y的最长上升子序列
        int len = 1;
        vector<int> d(n + 1);
        d[1] = data[0][1];
        for (int idx = 1; idx < n; ++idx) {
            if (data[idx][1] > d[len]) d[++len] = data[idx][1];
            else {
                int left = 1, right = len;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (data[idx][1] > d[mid]) left = mid + 1;
                    else right = mid;
                }
                d[left] = data[idx][1];
            }
        }
        cout << len << endl;
    }
    return 0;
}