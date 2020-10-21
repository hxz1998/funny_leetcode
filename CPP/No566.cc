/**
 * Created by Xiaozhong on 2020/10/20.
 * Copyright (c) 2020/10/20 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m = nums.size(), n = nums.front().size();
        if ((m * n) != (r * c)) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[index / c][index % c] = nums[i][j];
                ++index;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {
            {1, 2},
            {3, 4}
    };

    vector<vector<int>> ans = s.matrixReshape(nums, 1, 4);
//    cout <<  << endl;
}