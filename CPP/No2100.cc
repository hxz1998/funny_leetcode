/**
 * Created by Xiaozhong on 2022/3/6.
 * Copyright (c) 2022/3/6 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = (int) security.size();
        vector<int> left(n), right(n);
        for (int idx = 0; idx < n; ++idx) {
            if (idx == 0 || idx == n - 1) {
                left[idx] = 0;
                right[n - idx - 1] = 0;
            } else {
                if (security[idx - 1] >= security[idx]) left[idx] = left[idx - 1] + 1;
                else left[idx] = 0;
                if (security[n - idx] >= security[n - idx - 1]) right[n - idx - 1] = right[n - idx] + 1;
                else right[n - idx - 1] = 0;
            }
        }
        vector<int> ans;
        for (int day = time; day < n - time; ++day) {
            if (left[day] >= time && right[day] >= time) ans.emplace_back(day);
        }
        return ans;
    }
};

int main() {
    int num = move(3);
}