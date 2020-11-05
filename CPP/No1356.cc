/**
 * Created by Xiaozhong on 2020/11/6.
 * Copyright (c) 2020/11/6 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    int check(int num) {
        int ret = 0;
        while (num > 0) {
            ret += num & 1;
            num >>= 1;
        }
        return ret;
    }

public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<pair<int, int>> count;
        for (auto &num : arr) {
            int ret = check(num);
            count.emplace_back(make_pair(num, ret));
        }
        sort(count.begin(), count.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
        });
        vector<int> ans;
        for (auto p : count) ans.emplace_back(p.first);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = s.sortByBits(arr);
    for (int i : ans) cout << i << " ";
}