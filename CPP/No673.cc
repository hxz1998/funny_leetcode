/**
 * Created by Xiaozhong on 2020/11/11.
 * Copyright (c) 2020/11/11 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> lengths(n), count(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (lengths[i] <= lengths[j]) {
                        lengths[i] = lengths[j] + 1;
                        count[i] = count[j];
                    } else if (lengths[j] + 1 == lengths[i]) count[i] += count[j];
                }
            }
        }
        int ans = 0, lengthest = *max_element(lengths.begin(), lengths.end());
        for (int i = 0; i < n; ++i) {
            if (lengths[i] == lengthest) ans += count[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 5, 5, 7};
    cout << s.findNumberOfLIS(nums) << endl;
}