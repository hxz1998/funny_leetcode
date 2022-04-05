/**
 * Created by Xiaozhong on 2022/4/2.
 * Copyright (c) 2022/4/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = static_cast<int>(triangle.size()), m = static_cast<int>(triangle.back().size());
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = triangle[0][0];
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col <= row; ++col) {
                if (col == 0) dp[row][col] = triangle[row][col] + dp[row - 1][col];
                else if (col == row) dp[row][col] = triangle[row][col] + dp[row - 1][col - 1];
                else {
                    dp[row][col] = triangle[row][col] + min(dp[row - 1][col - 1], dp[row - 1][col]);
                }
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main() {
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
}