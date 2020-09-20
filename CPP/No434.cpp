/**
 * Created by Xiaozhong on 2020/9/20.
 * Copyright (c) 2020/9/20 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<string> split(string s) {
        vector<string> res;
        string buf = "";
        for (char c : s) {
            if (c != ' ') buf.push_back(c);
            else if (c == ' ' && buf.size() != 0) {
                res.push_back(buf);
                buf = "";
            }
        }
        if (buf.length() != 0) res.push_back(buf);
        return res;
    }

public:
    int countSegments(string s) {
        if (s.length() == 0) return 0;
        return split(s).size();
    }
};

int main() {
    Solution s;
    cout << s.countSegments("Hello, my name is John") << endl;
    cout << s.countSegments("                ") << endl;
}