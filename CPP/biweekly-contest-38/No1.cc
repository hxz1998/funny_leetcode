/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int> &nums) {
        unordered_map<int, int> counter;
        for (int i : nums) ++counter[i];
        vector<pair<int, int>> mapper;
        for (auto iter : counter)
            mapper.emplace_back(make_pair(iter.first, iter.second));
        sort(mapper.begin(), mapper.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second == rhs.second ? lhs.first > rhs.first : lhs.second < rhs.second;
        });
        vector<int> ans;
        for (auto iter : mapper) {
            for (int i = 0; i < iter.second; ++i)
                ans.push_back(iter.first);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> ans = s.frequencySort(nums);
    return 0;
}