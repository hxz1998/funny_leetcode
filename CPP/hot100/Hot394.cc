/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "stack"
#include "vector"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<bool> visited(s.length(), false);
        string ans;
        for (int idx = 0; idx < s.length(); ++idx) {
            if (!visited[idx] && isdigit(s[idx])) {
                ans.append(build(s, visited, idx));
            } else if (!visited[idx] && islower(s[idx])) ans.push_back(s[idx]);
        }
        return ans;
    }

private:
    string build(const string &s, vector<bool> &visited, int start) {
        int times = 0;
        string buffer;
        for (int idx = start; idx < s.length(); ++idx) {
            if (visited[idx]) continue;
            visited[idx] = true;
            if (isdigit(s[idx])) {
                if (!buffer.empty() || (idx > 0 && s[idx - 1] == '[' && times != 0)) {
                    visited[idx] = false;
                    buffer.append(build(s, visited, idx));
                } else times = times * 10 + s[idx] - '0';
            } else if (islower(s[idx])) {
                buffer.push_back(s[idx]);
            } else if (s[idx] == ']') break;
        }
        string ret;
        for (int time = 0; time < times; ++time) {
            ret.append(buffer);
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("abc3[cd]xyz") << endl << "abccdcdcdxyz" << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl << "abcabccdcdcdef" << endl;
    cout << s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;
}