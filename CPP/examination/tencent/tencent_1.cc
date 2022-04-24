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
    vector<string> strs(n);
    vector<int> nums;
    for (int idx = 0; idx < n; ++idx) {
        cin >> strs[idx];
    }
    int length = strs.front().size();
    for (int i = 0; i < length; ++i) {
        int num = 0;
        for (int idx = 0; idx < n; ++idx) {
            num = num * 10 + (strs[idx][i] - '0');
        }
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    for (int idx = 0; idx < length; ++idx) cout << nums[idx] << " ";
}