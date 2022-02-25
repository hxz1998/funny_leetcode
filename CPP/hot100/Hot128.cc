/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numsSet;
        for (int num: nums) numsSet.insert(num);

        int longestLength = 0;
        for (const int &num: nums) {
            if (numsSet.find(num - 1) != numsSet.end()) {
                int currNum = num;
                int currLength = 1;
                while (numsSet.find(currNum + 1) != numsSet.end()) {
                    currNum++;
                    currLength++;
                }
                longestLength = max(longestLength, currLength);
            }
        }
        return longestLength;
    }
};