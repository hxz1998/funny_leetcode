/**
 * Created by Xiaozhong on 2020/11/12.
 * Copyright (c) 2020/11/12 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        int sz = A.size();
        int odd = 1, even = 0;
        for (; even < sz; even += 2) {
            if (A[even] & 1) {
                while (A[odd] & 1) odd += 2;
                swap(A[odd], A[even]);
            }
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 0, 4, 0, 2, 1, 3, 1, 3, 4};
    s.sortArrayByParityII(nums);
    return 0;
}