/**
 * Created by Xiaozhong on 2022/3/21.
 * Copyright (c) 2022/3/21 Xiaozhong. All rights reserved.
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
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int idx = 0; idx < 32; ++idx) {
            int total = 0;
            for (int num: nums) {
                total += ((1 << idx) & num) != 0 ? 1 : 0;
            }
            ans |= (total % 3) << idx;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, 2};
    Solution s;
    cout << s.singleNumber(nums) << endl;
}