/**
 * Created by Xiaozhong on 2020/11/30.
 * Copyright (c) 2020/11/30 Xiaozhong. All rights reserved.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[idx]) idx = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != idx && nums[idx] < 2 * nums[i]) return -1;
        }
        return idx;
    }
};

int main () {

}