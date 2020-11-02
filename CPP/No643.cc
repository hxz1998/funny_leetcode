/**
 * Created by Xiaozhong on 2020/11/2.
 * Copyright (c) 2020/11/2 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double sum = 0.0;
        for (int i = 0; i < k; ++i) sum += nums[i];
        double ans = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum = sum + nums[i] - nums[i - k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << s.findMaxAverage(nums, 4) << endl;
    nums = {0, 1, 1, 3, 3};
    cout << s.findMaxAverage(nums, 4) << endl;
    nums = {4, 0, 4, 3, 3};
    cout << s.findMaxAverage(nums, 5) << endl;
}