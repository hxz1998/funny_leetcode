/**
 * Created by Xiaozhong on 2021/12/16.
 * Copyright (c) 2021/12/16 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0, right = 0;
        unordered_set<char> st;
        st.insert(s[right++]);
        while (right < s.size()) {
            while (right < s.size() && st.find(s[right]) == st.end())
                st.insert(s[right++]);
            ans = max(ans, (int) st.size());
            if (right == s.size()) return ans;
            while (left < right && st.find(s[right]) != st.end())
                st.erase(s[left++]);
            st.insert(s[right++]);
        }
        return max(ans, (int) st.size());
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");
}