/**
 * Created by Xiaozhong on 2022/3/11.
 * Copyright (c) 2022/3/11 Xiaozhong. All rights reserved.
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
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        vector<int> cnt(52, 0), target(52, 0);
        int n = static_cast<int>(s.size()), m = static_cast<int>(t.size());
        if (n < m) return "";
        for (const char &c: t) {
            if (islower(c)) target[c - 'a']++;
            else target[c - 'A' + 26]++;
        }
        string ans = s;
        while (true) {
            while (right < n && !check(cnt, target)) {
                if (islower(s[right])) cnt[s[right] - 'a']++;
                else cnt[s[right] - 'A' + 26]++;
                right++;
            }
            while (left < right && check(cnt, target)) {
                if (ans.length() > right - left) ans = s.substr(left, right - left);
                if (islower(s[left])) cnt[s[left] - 'a']--;
                else cnt[s[left] - 'A' + 26]--;
                left++;
            }
            if (right >= n) break;
        }
        return ans;
    }

private:
    inline bool check(const vector<int> &cnt, const vector<int> &target) {
        for (int idx = 0; idx < 52; ++idx) {
            if (cnt[idx] < target[idx]) return false;
        }
        return true;
    }
};