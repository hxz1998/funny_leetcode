/**
 * Created by Xiaozhong on 2021/1/5.
 * Copyright (c) 2021/1/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int left = 0, right = A.size() - 1;
        while (left < right) {
            while (left < right && (A[left] & 1) == 0) ++left;
            while (right > left && (A[right] & 1) == 1) --right;
            swap(A[left], A[right]);
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<int> A = {3, 1, 2, 4};
    vector<int> ans = s.sortArrayByParity(A);
    return 0;
}