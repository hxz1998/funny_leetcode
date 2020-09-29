/**
 * Created by Xiaozhong on 2020/9/29.
 * Copyright (c) 2020/9/29 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int res = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (const auto &house : houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (house > heaters[mid]) left = mid + 1;
                else right = mid;
            }
            int dist1 = (right == 0) ? INT32_MAX : abs(house - heaters[right - 1]);
            int dist2 = (right == n) ? INT32_MAX : abs(house - heaters[right]);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
