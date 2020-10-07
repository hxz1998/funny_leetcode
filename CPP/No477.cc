/**
 * Created by Xiaozhong on 2020/9/30.
 * Copyright (c) 2020/9/30 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        if (nums.empty()) return 0;
        int ans = 0, n = nums.size();
        vector<int> cnt(31, 0);
        for (int &num : nums) {
            int i = 0;
            while (num) {
                cnt[i++] += (num & 1);
                num >>= 1;
            }
        }

        for (auto &k : cnt) {
            ans += k * (n - k);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 14, 2};
    cout << s.totalHammingDistance(nums) << endl;
}