/**
 * Created by Xiaozhong on 2020/9/26.
 * Copyright (c) 2020/9/26 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (g.size() == 0 || s.size() == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        for (; i < g.size() && j < s.size(); ++i, ++j) {
            while (i < g.size() && j < s.size() && g[i] > s[j]) {
                ++j;
                if (j == s.size()) return i;
            }
        }
        return i;
    }
};

int main() {
    vector<int> g = {10, 9, 8, 7};
    vector<int> s = {5, 6, 7, 8};
    Solution solution;
    cout << solution.findContentChildren(g, s) << endl;
    g = {1, 2, 3};
    s = {1, 1};
    cout << solution.findContentChildren(g, s) << endl;
}