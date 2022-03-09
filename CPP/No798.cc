/*
 * Created by Xiaozhong on 3/9/2022.
 * Copyright (c) 3/9/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
public:
    int bestRotation(vector<int> &nums) {
        function<void(int, int, vector<int> &)> add = [](int left, int right, vector<int> &cnt) {
            cnt[left]++;
            cnt[right + 1]--;
        };

        int n = static_cast<int>(nums.size());
        vector<int> cnt(n + 1);
        for (int idx = 0; idx < n; ++idx) {
            int a = (idx - (n - 1) + n) % n, b = (idx - nums[idx] + n) % n;
            if (a <= b) {
                add(a, b, cnt);
            } else {
                add(0, b, cnt);
                add(a, n - 1, cnt);
            }
        }

        for (int idx = 1; idx <= n; ++idx) cnt[idx] = cnt[idx - 1] + cnt[idx];
        int ans = 0;
        int score = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (cnt[idx] > score) {
                ans = idx;
                score = cnt[idx];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 4, 0};
    cout << s.bestRotation(nums) << endl;
}