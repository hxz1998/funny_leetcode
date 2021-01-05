/**
 * Created by Xiaozhong on 2021/1/5.
 * Copyright (c) 2021/1/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> split(string addr, char delimiter = '@') {
        vector<string> ans;
        string buf;
        addr.push_back('@');
        for (char c : addr) {
            if (c == delimiter) {
                ans.emplace_back(buf);
                buf = "";
            } else {
                buf.push_back(c);
            }
        }
        return ans;
    }

public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_map<string, unordered_set<string>> mapper;
        for (const string &email : emails) {
            vector<string> s = split(email);
            string addr;
            for (char c : s.front()) {
                if (c == '+') break;
                else if (c == '.') continue;
                else addr.push_back(c);
            }
            mapper[s.back()].insert(addr);
        }
        int ans = 0;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            ans += iter->second.size();
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                             "testemail+david@lee.tcode.com"};
    cout << s.numUniqueEmails(emails);
}