/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "unordered_set"
#include "iostream"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, 1, 1};
    cout << s.containsNearbyDuplicate(nums,1) << endl;
}