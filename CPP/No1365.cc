/**
* Created by Xiaozhong on 2020/10/26.
* Copyright (c) 2020/10/26 Xiaozhong. All rights reserved.
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        map<int, int> mapper;
        for (int i = 0; i < nums.size(); ++i) mapper[nums[i]]++;
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (map<int, int>::iterator iter = mapper.begin(); iter != mapper.end(); ++iter) {
                if (iter->first < nums[i]) ans[i] += iter->second;
                else break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> ans = s.smallerNumbersThanCurrent(nums);
    for (auto i : ans) cout << i << " ";
}
