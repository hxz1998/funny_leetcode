/**
 * Created by Xiaozhong on 2022/3/22.
 * Copyright (c) 2022/3/22 Xiaozhong. All rights reserved.
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
    bool checkInclusion(string s1, string s2) {
        vector<int> target(26);
        function<bool(const vector<int> &)> matches = [&](const vector<int> &cnt) {
            for (int idx = 0; idx < 26; ++idx) if (target[idx] != cnt[idx]) return false;
            return true;
        };
        for (char c: s1) target[c - 'a']++;
        vector<int> cnt(26, 0);
        int right = 0, left = 0, n = static_cast<int>(s1.size()), m = static_cast<int>(s2.size());
        if (n > m) return false;
        while (right < n) cnt[s2[right++] - 'a']++;
        while (right < m) {
            if (matches(cnt)) return true;
            cnt[s2[right++] - 'a']++;
            cnt[s2[left++] - 'a']--;
        }
        return matches(cnt);
    }
};