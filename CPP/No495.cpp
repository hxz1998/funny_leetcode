/**
 * Created by Xiaozhong on 2020/10/2.
 * Copyright (c) 2020/10/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int count = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            count += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return count + duration;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2};
    cout << s.findPoisonedDuration(nums, 2);
}