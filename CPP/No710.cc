/**
 * Created by Xiaozhong on 2020/11/21.
 * Copyright (c) 2020/11/21 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    int n;
    vector<int> b;
public:
    Solution(int N, vector<int> &blacklist) {
        n = N;
        sort(blacklist.begin(), blacklist.end());
        b = blacklist;
    }

    int pick() {
        int k = rand() % (n - b.size());
        int low = 0, high = b.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (b[mid] - mid > k) high = mid - 1;
            else low = mid;
        }
        return low == high && b[low] - low <= k ? k + low + 1 : k;
    }
};