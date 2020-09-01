/**
 * Created by Xiaozhong on 2020/9/1.
 * Copyright (c) 2020/9/1 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
private:
    bool check(vector<vector<int>> &matrix, int mid, int k, int n) {
        int count = 0, i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            // 如果元素小于等于 mid, 那么就向右以动,并且把当前列中不大于 mid 的数量累加起来
            if (matrix[i][j] <= mid) {
                j++;            // 右移
                count += i + 1; // 累加和
            } else {
                i--;            // 否则就上移
            }
        }
        return count >= k;
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // 这种方法比较直接, 但是也可行
/*
        vector<int> nums;
        for (int i = 0; i < matrix.size(); ++i) for (int j = 0; j < matrix[0].size(); ++j) nums.push_back(matrix[i][j]);
        sort(nums.begin(), nums.end());
        return nums[k - 1];
*/
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) { // 如果 mid 太大, 那么就调整右指针
                right = mid;
            } else {
                left = mid + 1;                 // 否则就调整左指针
            }
        }
        return left;    //
    }
};