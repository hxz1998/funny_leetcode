/*
 * Created by Xiaozhong on 3/2/2022.
 * Copyright (c) 3/2/2022 Xiaozhong. All rights reserved.
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
    int subarraySum(vector<int> &nums, int k) {
        size_t n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 0;
        int ans = 0, pre = 0;
        for (int num: nums) {
            pre += num;
            if (cnt.find(pre - k) != cnt.end()) {
                ans += cnt[pre - k];
            }
            cnt[num]++;
        }
        return ans;
    }
};