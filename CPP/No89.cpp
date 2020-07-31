/**
 * Created by Xiaozhong on 2020/7/30.
 * Copyright (c) 2020/7/30 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1);
        ans[0] = 0;
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = ans.size() - 1; j >= 0; j--)
                ans.push_back(head + ans.at(j));
            head <<= 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.grayCode(3);
    for (int i : ans) {
        cout << i << " ";
    }
}
