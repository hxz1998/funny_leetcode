/**
 * Created by Xiaozhong on 2020/10/25.
 * Copyright (c) 2020/10/25 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int> &A) {
        if (A.empty()) return 0;
        vector<int> left(A.size(), 0), right(A.size(), 0);
        for (int i = 1; i < A.size(); ++i)
            // 从左向右检查最长递增子序列长度，并记录在 [i] 下
            if (A[i] > A[i - 1])
                left[i] = left[i - 1] + 1;
        for (int i = A.size() - 1; i > 0; --i)
            // 从右向左检查最长递减子序列长度，并记录在 [i] 下
            if (A[i] < A[i - 1])
                right[i - 1] = right[i] + 1;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            // 以 i 为分界点，检查左右最长递增最长递减子序列长度
            if (left[i] > 0 && right[i] > 0)
                // 之所以要大于零，是因为防止出现 2 2 2 这样的不增不减序列
                ans = max(ans, left[i] + right[i] + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {2, 1, 4, 7, 3, 2, 5};
    cout << s.longestMountain(A) << endl;
    A = {2, 2, 2};
    cout << s.longestMountain(A) << endl;
}