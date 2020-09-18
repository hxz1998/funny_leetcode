/**
 * Created by Xiaozhong on 2020/9/18.
 * Copyright (c) 2020/9/18 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int ans = 0;
        int mask = 0;
        for (int i = 30; i >= 0; --i) {
            mask = mask | (1 << i);
            unordered_set<int> set;
            for (int num : nums) {
                set.insert(num & mask);
            }
            int temp = ans | (1 << i);
            for (int prefix : set) {
                if (set.count(prefix ^ temp)) {
                    ans = temp;
                    break;
                }
            }
        }
        return ans;
    }
};