/**
 * Created by Xiaozhong on 2020/12/9.
 * Copyright (c) 2020/12/9 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string s) {
        vector<int> ans(2, 0);
        int length = 0;
        for (char c : s) {
            if (length + widths[c - 'a'] <= 100) length += widths[c - 'a'];
            else {
                length = widths[c - 'a'];
                ans.front()++;
            }
        }
        ans.front()++;
        ans.back() = length;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                          10, 10};
    vector<int> ans = s.numberOfLines(widths, "bbbcccdddaaa");
    cout << ans.front() << " " << ans.back() << endl;
    widths = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    ans = s.numberOfLines(widths, "abcdefghijklmnopqrstuvwxyz");
    cout << ans.front() << " " << ans.back() << endl;
}