/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "cmath"
#include "unordered_map"

using namespace std;

class Solution {
public:
    string minNumber(vector<int> &nums) {
        unordered_map<int, string> mapper;
        for (int num: nums) mapper[num] = to_string(num);
        sort(nums.begin(), nums.end(), [&](int &lhs, int &rhs) {
            return mapper[lhs] + mapper[rhs] < mapper[rhs] + mapper[lhs];
        });
        string ans;
        for (int num: nums) {
            ans.append(to_string(num));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution s;
    cout << s.minNumber(nums) << endl;
}