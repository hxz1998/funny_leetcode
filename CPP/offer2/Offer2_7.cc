/**
 * Created by Xiaozhong on 2022/3/13.
 * Copyright (c) 2022/3/13 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = static_cast<int>(nums.size());
        for (int left = 0; left <= n - 3; ++left) {
            if (left > 0 && nums[left] == nums[left - 1]) continue;
            int mid = left + 1, right = n - 1;
            int target = -nums[left];
            while (mid < right) {
                int sum = nums[mid] + nums[right];
                if (sum < target) {
                    mid++;
                } else if (sum > target) {
                    right--;
                } else {
                    if (mid > left + 1 && nums[left] != nums[mid]) ans.push_back({nums[left], nums[mid], nums[right]});
                    mid++;
                    right--;
                }
            }
        }

//        int left = 0, right = n - 1;
//        while (left < right) {
//            int target = nums[left] + nums[right];
//            if (target < nums[left]) left++;
//            else if (target > nums[right]) right--;
//            else {
//                if (binary_search(nums.begin() + left + 1, nums.begin() + right, -target)) {
//                    ans.push_back({nums[left], -target, nums[right]});
//                }
//                left++;
//                right--;
//            }
//        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    s.threeSum(nums);
}