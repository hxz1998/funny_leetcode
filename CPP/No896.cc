/**
 * Created by Xiaozhong on 2020/12/25.
 * Copyright (c) 2020/12/25 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        int n = A.size();
        if (n == 1) return true;
        auto cmp = [](int lhs, int rhs) {
            if (lhs < rhs) return -1;
            else if (lhs > rhs) return 1;
            else return 0;
        };
        int store = cmp(A[0], A[1]);
        for (int i = 1; i < n - 1; ++i) {
            int c = cmp(A[i], A[i + 1]);
            if (c != 0) {
                if (c != store && store != 0) {
                    return false;
                }
                store = c;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 3};
    cout << s.isMonotonic(nums) << endl;
    nums = {1, 1, 0};
    cout << s.isMonotonic(nums) << endl;
}