/**
 * Created by Xiaozhong on 2022/3/22.
 * Copyright (c) 2022/3/22 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;
        unordered_map<int, int> mapper;
        int counter = 0;
        mapper[counter] = -1;
        int prev = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (nums[idx] == 1) prev += 1;
            else prev -= 1;
            if (mapper.find(prev) != mapper.end()) {
                int i = mapper[prev];
                ans = max(ans, idx - i);
            } else mapper[prev] = idx;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 1};
    cout << s.findMaxLength(nums) << endl;
    nums = {0, 1};
    cout << s.findMaxLength(nums) << endl;
}