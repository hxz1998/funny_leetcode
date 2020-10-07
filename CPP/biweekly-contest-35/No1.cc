/**
 * Created by Xiaozhong on 2020/9/19.
 * Copyright (c) 2020/9/19 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int len = arr.size(), ans = 0;
        for (int i = 1; i <= len; i += 2) {
            for (int start = 0; start <= len - i; start += 1) {
                for (int j = 0; j < i; ++j) {
                    ans += arr[start + j];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 4, 2, 5, 3};
    cout << s.sumOddLengthSubarrays(nums) << endl;
    nums = {1, 2};
    cout << s.sumOddLengthSubarrays(nums) << endl;
}