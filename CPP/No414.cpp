/**
 * Created by Xiaozhong on 2020/9/16.
 * Copyright (c) 2020/9/16 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long long first = -3e9, second = -3e9, third = -3e9;
        for (long long num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        return third == -3e9 ? first : third;
    }
};

int main() {
    Solution s;
//    vector<int> nums = {3, 2, 1};
    vector<int> nums = {1, 2, -2147483648};
    cout << s.thirdMax(nums) << endl;
}