/**
 * Created by Xiaozhong on 2020/12/8.
 * Copyright (c) 2020/12/8 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int ans = 0, mx = 0;
        for (int i = 0; i < arr.size(); ++i) {
            mx = max(mx, arr[i]);
            if (mx == i) ++ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 3, 2, 1, 0};
    cout << s.maxChunksToSorted(nums) << endl;
    nums = {1, 0, 2, 3, 4};
    cout << s.maxChunksToSorted(nums) << endl;
}