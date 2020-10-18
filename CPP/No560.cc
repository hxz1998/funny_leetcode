/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mapper;
        mapper[0] = 1;
        int pre = 0, count = 0;
        for (auto &num : nums) {
            pre += num;
            if (mapper.find(pre - k) != mapper.end()) {
                count += mapper[pre - k];
            }
            mapper[pre]++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << s.subarraySum(nums, 2) << endl;
}