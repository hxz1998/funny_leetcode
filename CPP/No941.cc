/**
 * Created by Xiaozhong on 2020/11/3.
 * Copyright (c) 2020/11/3 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() < 3) return false;
        int left = 0, right = A.size() - 1;
        while (left <= A.size() - 2 && A[left + 1] > A[left]) ++left;
        while (right >= 1 && A[right] < A[right - 1]) --right;
        return left == right && left != 0 && right != A.size() - 1;
    }
};

int main() {
    Solution s;
    vector<int> A = {3, 5, 5};
    cout << s.validMountainArray(A) << endl;
    A = {0, 3, 2, 1};
    cout << s.validMountainArray(A) << endl;
    A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.validMountainArray(A) << endl;
}