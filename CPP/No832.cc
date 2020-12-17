/**
 * Created by Xiaozhong on 2020/12/16.
 * Copyright (c) 2020/12/16 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        // 记下来数组维度
        int n = A.size(), m = A.front().size();
        // 逐行处理
        for (int i = 0; i < n; ++i) {
            // 双指针处理，一个指向左边第一个，一个指向右边最后一个
            int left = 0, right = m - 1;
            // 然后进行翻转 + 反转
            while (left <= right) {
                int tmp = A[i][left];
                // 需要进行反转，所以异或上 1
                A[i][left] = A[i][right] ^ 1;
                A[i][right] = tmp ^ 1;
                ++left;
                --right;
            }
        }
        return A;
    }
};

