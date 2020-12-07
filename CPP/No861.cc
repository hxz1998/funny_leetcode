/**
 * Created by Xiaozhong on 2020/12/7.
 * Copyright (c) 2020/12/7 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>> &A) {
        int m = A.size(), n = A.front().size();
        // 因为必须每一列的第一个都要是 1， 所以可以直接把这组数加上来
        int ret = m * (1 << (n - 1));
        // 然后检查除第一列之外的所有列，其他列只要是 1 多，那么就不反转，否则就反转
        for (int i = 1; i < n; ++i) {
            int nOnes = 0;  // 统计当前列中 1 的个数
            // 检查所有行，如果行首元素为1，那么说明这一行没变过，直接加就好，否则需要加上变换过的
            for (int j = 0; j < m; ++j) {
                if (A[j][0] == 1) {
                    nOnes += A[j][i];
                } else {
                    nOnes += (1 - A[j][i]);
                }
            }
            // 看看是 1 多还是 0 多，取多的那个
            int k = max(nOnes, m - nOnes);
            // 把当前列代表的所有 1 进行累加到返回值中
            ret += k * (1 << (n - i - 1));
        }
        return ret;
    }
};