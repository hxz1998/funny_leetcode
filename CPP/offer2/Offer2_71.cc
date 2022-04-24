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
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> prev;
    int sum = 0;
public:
    Solution(vector<int> &w) : gen(random_device{}()) {
        int n = static_cast<int>(w.size());
        prev.resize(n);
        for (int idx = 0; idx < n; ++idx) {
            if (idx == 0) prev[idx] = w[idx];
            else prev[idx] = prev[idx - 1] + w[idx];
            sum += w[idx];
        }
        dis = uniform_int_distribution<int>(0, sum - 1);
    }

    int pickIndex() {
        int num = dis(gen);
        int left = 0, right = static_cast<int>(prev.size() - 1);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prev[mid] <= num) left = mid + 1;
            else if (prev[mid] > num) right = mid;
        }
        return left;
    }
};
