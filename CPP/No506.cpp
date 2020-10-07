/**
 * Created by Xiaozhong on 2020/10/6.
 * Copyright (c) 2020/10/6 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<string> ans(nums.size());
        map<int, int, greater<int>> mapper;
        for (int i = 0; i < nums.size(); ++i) {
            mapper[nums[i]] = i;
        }
        int rank = 0;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            switch (rank) {
                case 0:
                    ans[iter->second] = "Gold Medal";
                    ++rank;
                    break;
                case 1:
                    ans[iter->second] = "Silver Medal";
                    ++rank;
                    break;
                case 2:
                    ans[iter->second] = "Bronze Medal";
                    ++rank;
                    break;
                default:
                    ans[iter->second] = to_string(rank + 1);
                    ++rank;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<string> ans = s.findRelativeRanks(nums);
    for (string item : ans) {
        cout << item << endl;
    }
    nums = {10, 3, 8, 9, 4};
    ans = s.findRelativeRanks(nums);

    for (string item : ans) {
        cout << item << endl;
    }
}