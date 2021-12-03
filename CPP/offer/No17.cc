/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int cnt = 9;
        while (--n > 0) {
            cnt *= 10;
        }
        vector<int> ans(cnt);
        for (int i = 1; i <= cnt; ++i) ans[i - 1] = i;
        return ans;
    }
};


ostream &operator<<(ostream &os, const vector<int> &data) {
    for (int num: data) os << num << " ";
    return os;
}

int main() {
    Solution s;
    cout << s.printNumbers(1) << endl;
}