/**
 * Created by Xiaozhong on 2020/12/6.
 * Copyright (c) 2020/12/6 Xiaozhong. All rights reserved.
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        for (auto i : nums) counter[i]++;
        int ans = 0;
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            int n = iter->first;
            if (iter->second != 0 && counter.count(k - n) && counter[k - n] != 0) {
                if (k - n == n) {
                    ans += counter[k - n] / 2;
                    counter[k - n] /= 2;
                } else {
                    int count = min(counter[k - n], counter[n]);
                    ans += count;
                    counter[n] -= count;
                    counter[k - n] -= count;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 3, 4, 3};
    cout << s.maxOperations(nums, 6) << endl;
    nums = {1, 2, 3, 4};
    cout << s.maxOperations(nums, 5) << endl;
}