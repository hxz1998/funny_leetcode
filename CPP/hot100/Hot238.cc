/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> leftProduct(n, 0);
        vector<int> rightProduct(n, 0);
        leftProduct[0] = nums[0];
        rightProduct[n - 1] = nums[n - 1];
        for (int idx = 1; idx < n; ++idx) leftProduct[idx] = leftProduct[idx - 1] * nums[idx];
        for (int idx = n - 2; idx >= 0; --idx) rightProduct[idx] = rightProduct[idx + 1] * nums[idx];
        vector<int> ans(n);
        for (int idx = 0; idx < n; ++idx) {
            if (idx == 0) ans[idx] = rightProduct[1];
            else if (idx == n - 1) ans[idx] = leftProduct[n - 2];
            else ans[idx] = leftProduct[idx - 1] * rightProduct[idx + 1];
        }
        return ans;
    }
};

ostream &operator<<(ostream &os, const vector<int> &data) {
    for (int num: data) os << num << " ";
    return os;
}

int main() {
    vector<int> nums = {1, 2};
    Solution s;
    cout << s.productExceptSelf(nums) << endl;
}