/**
 * Created by Xiaozhong on 2020/11/19.
 * Copyright (c) 2020/11/19 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> count;
        int n = s.size(), ptr = 0;
        while (ptr < n) {
            int num = 0;
            char c = s[ptr];
            while (s[ptr] == c) {
                ++num;
                ++ptr;
            }
            count.emplace_back(num);
        }
        int ans = 0;
        for (int i = 1; i < count.size(); ++i) {
            ans += min(count[i], count[i - 1]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countBinarySubstrings("00110011") << endl;
}