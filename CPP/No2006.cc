/**
 * Created by Xiaozhong on 2022/2/9.
 * Copyright (c) 2022/2/9 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int num: nums) {
            ans += cnt[k - num] > 0 ? cnt[k - num] : 0;
            ans += cnt[num - k] > 0 ? cnt[num - k] : 0;
            cnt[num]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 1};
    cout << s.countKDifference(nums, 1) << endl;
}