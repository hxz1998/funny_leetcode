/**
 * Created by Xiaozhong on 2021/4/5.
 * Copyright (c) 2021/4/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int purchasePlans(vector<int> &nums, int target) {
        int mod = 1e9 + 7;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            vector<int>::iterator next = upper_bound(nums.begin(), nums.end(), target - *iter);
            if (next > iter) ans += next - nums.begin() - 1;
            else ans += next - nums.begin() + 1;
            ans %= mod;
        }
        return ans % mod;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 5, 3, 5};
    solution.purchasePlans(nums, 6);
}