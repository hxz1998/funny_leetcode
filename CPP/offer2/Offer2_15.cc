/**
 * Created by Xiaozhong on 2022/3/23.
 * Copyright (c) 2022/3/23 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = static_cast<int>(s.size()), m = static_cast<int>(p.size());
        if (n < m) return {};
        vector<int> target(26);
        function<bool(const vector<int> &)> matches = [&](const vector<int> &cnt) {
            for (int idx = 0; idx < 26; ++idx) if (target[idx] != cnt[idx]) return false;
            return true;
        };
        for (const char &c: p) target[c - 'a']++;
        vector<int> ans;
        vector<int> cnt(26);
        for (int idx = 0; idx < m; ++idx) cnt[s[idx] - 'a']++;
        for (int left = 0; left < n - m; ++left) {
            if (matches(cnt)) ans.push_back(left);
            cnt[s[left] - 'a']--;
            cnt[s[left + m] - 'a']++;
        }
        if (matches(cnt)) ans.push_back(n - m);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.findAnagrams("cbaebabacd", "abc");
    for (int num: ans) cout << num << " ";
}