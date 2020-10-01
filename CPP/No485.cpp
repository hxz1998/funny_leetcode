/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int ans = 0;
        int count = 0;
        for (const int &num : nums) {
            if (num) ++count;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        return max(ans, count);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 0, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
}