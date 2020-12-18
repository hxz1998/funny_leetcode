/**
 * Created by Xiaozhong on 2020/12/18.
 * Copyright (c) 2020/12/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int ans = 0, max_ele = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > max_ele) {
                ans = i;
                max_ele = arr[i];
            }
        }
        return ans;
    }
};