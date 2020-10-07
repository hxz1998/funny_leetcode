/**
 * Created by Xiaozhong on 2020/8/6.
 * Copyright (c) 2020/8/6 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans({1});
        if (!rowIndex) return ans;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
                if (j == 0 || j == i) temp.push_back(1); else temp.push_back(ans[j] + ans[j - 1]);
            ans = temp;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.getRow(5);
    for (int i : ans) {
        cout << i << " ";
    }
}