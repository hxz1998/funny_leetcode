/*
 * Created by Xiaozhong on 3/3/2022.
 * Copyright (c) 3/3/2022 Xiaozhong. All rights reserved.
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
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
private:
    inline bool helper(const vector<int> &curr, const vector<int> &target) {
        for (size_t idx = 0; idx < 26; ++idx) if (curr[idx] != target[idx]) return false;
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        size_t left = 0, right = p.size() - 1;
        vector<int> target(26, 0);
        vector<int> curr(26, 0);
        for (size_t idx = 0; idx < p.size(); ++idx) {
            curr[s[idx] - 'a']++;
            target[p[idx] - 'a']++;
        }
        vector<int> ans;
        while (right < s.size()) {
            if (helper(curr, target)) ans.push_back((int) left);
            curr[s[left++] - 'a']--;
            if (right < s.size() - 1) curr[s[++right] - 'a']++;
            else {
                if (helper(curr, target)) ans.push_back((int) left);
                return ans;
            }
        }
        return ans;
    }
};