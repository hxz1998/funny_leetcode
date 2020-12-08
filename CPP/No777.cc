/**
 * Created by Xiaozhong on 2020/12/8.
 * Copyright (c) 2020/12/8 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void replace(string &s, const string &pattern, const string &target) {
        size_t pos = s.find(pattern);
        while (pos != string::npos) {
            s.replace(pos, pattern.size(), target);
            pos = s.find(pattern);
        }
    }

public:
    bool canTransform(string start, string end) {
        string tmp_start = start, tmp_end = end;
        replace(tmp_start, "X", "");
        replace(tmp_end, "X", "");
        if (tmp_start != tmp_end) return false;
        int t = 0;
        for (int i = 0; i < start.size(); ++i) {
            if (start[i] == 'L') {
                while (end[t] != 'L') ++t;
                if (i < t++) return false;
            }
        }
        t = 0;
        for (int i = 0; i < start.size(); ++i) {
            if (start[i] == 'R') {
                while (end[t] != 'R') ++t;
                if (i > t++) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canTransform("RXXLRXRXL", "XRLXXRRLX") << endl;
    cout << s.canTransform("X", "R") << endl;
}