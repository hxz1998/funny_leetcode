/**
 * Created by Xiaozhong on 2020/10/24.
 * Copyright (c) 2020/10/24 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> counter;
        for (auto &item : nums) counter[item]++;

        int length = 0;
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            if (counter.count(iter->first + 1)) {
                length = max(length, iter->second + counter[iter->first + 1]);
            }
        }
        return length;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << s.findLHS(nums) << endl;
}