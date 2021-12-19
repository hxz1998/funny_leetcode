/**
 * Created by Xiaozhong on 2021/12/19.
 * Copyright (c) 2021/12/19 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int> &prices) {
        if (prices.size() == 1) return 1;
        long long ans = 0;
        long long len = 1;
        for (int i = 0; i < prices.size(); ++i) {
            if (i == 0) continue;
            if (prices[i - 1] - prices[i] == 1) len++;
            else if (len != 1) {
                ans += (len + 1) * len / 2;
                len = 1;
            } else {
                ans++;
            }
            if (i == prices.size() - 1 && len == 1) ans++;
        }
        if (len != 1) ans += (len + 1) * len / 2;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 4};
    cout << s.getDescentPeriods(nums) << endl;
    nums = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 4, 3, 10, 9, 8, 7};
    cout << s.getDescentPeriods(nums) << endl;
}