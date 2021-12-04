/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &lhs, const int &rhs) {
            return (lhs % 2 == 1 ? 1 : 0) > (rhs % 2 == 1 ? 1 : 0);
        });
        return nums;
    }
};

int main() {

}