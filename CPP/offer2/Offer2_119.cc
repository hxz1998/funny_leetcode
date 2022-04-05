/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
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
    int longestConsecutive(vector<int> &nums) {
        int ans = 0;
        unordered_set<int> uSet(nums.begin(), nums.end());
        for (int num: nums) {
            if (uSet.find(num - 1) != uSet.end()) continue;
            int longest = 1;
            int curr = num;
            while (uSet.find(++curr) != uSet.end()) longest++;
            ans = max(longest, ans);
        }
        return ans;
    }
};