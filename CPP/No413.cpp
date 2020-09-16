/**
 * Created by Xiaozhong on 2020/9/16.
 * Copyright (c) 2020/9/16 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        vector<int> dp(A.size(), 0);
        int sum = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.numberOfArithmeticSlices(nums);
}