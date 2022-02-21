/**
 * Created by Xiaozhong on 2020/10/14.
 * Copyright (c) 2020/10/14 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

// 0  1  2  3  4  5  6  7  8
// 1, 1, 2, 3, 3, 4, 4, 8, 8
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == nums[mid ^ 1]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};

/*inline int Solution::singleNonDuplicate(vector<int> &nums) {
    if (nums.empty()) return 0;
    int ans = nums.front();
    for (int i = 1; i < nums.size(); ++i) ans ^= nums[i];
    return ans;
}*/

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums) << endl;
}