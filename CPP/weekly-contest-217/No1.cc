/**
 * Created by Xiaozhong on 2020/11/29.
 * Copyright (c) 2020/11/29 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = 0;
        for (const vector<int> &account : accounts) {
            int tmp = 0;
            for (int i : account) tmp += i;
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> accounts = {
            {2, 8, 7},
            {7, 1, 3},
            {1, 9, 5}
    };
    cout << s.maximumWealth(accounts) << endl;
}
