/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "set"

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            auto lower = s.lower_bound(nums[i]);    // lower_bound(x) 寻找大于等于 x 的最小值
            /*
             * lower == s.end 时，代表没有找到
             * nums[i] + t >= g
             */
            if (lower != s.end() && *lower <= t + nums[i]) return true;
            auto upper = s.upper_bound(nums[i]);    // upper_bound(x) 寻找大于 x 的最小值
            /*
             * 之所以要使用 upper-- 是因为，这样直接找到的元素是正好大于 x 的，现在需要找到小于 x 的那个数，
             * 所以往前移一个就好了
             * nums[i] - t <= s
             */
            if (upper != s.begin() && nums[i] <= t + *(--upper)) return true;
            s.insert(nums[i]);                      // 把元素插入进来
            if (s.size() > k) s.erase(nums[i - k]); // 维护 set 大小不超过 k
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    cout << s.containsNearbyAlmostDuplicate(nums, 2, 3);
}