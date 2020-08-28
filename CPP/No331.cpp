/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    vector<string> split(string str, const char delimiter) {
        vector<string> res;
        string buffer = "";
        for (char c : str) {
            if (c != delimiter) buffer.push_back(c);
            else {
                res.push_back(buffer);
                buffer = "";
            }
        }
        res.push_back(buffer);
        return res;
    }

public:
    bool isValidSerialization(string preorder) {
        int solts = 1;
        vector<string> strs = split(preorder, ',');
        for (string item : strs) {
            --solts;
            if (solts < 0) return false;
            if (item != "#") solts += 2;
        }
        return solts == 0;
    }
};

int main() {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,#") << endl;
    cout << s.isValidSerialization("9,#,92,#,#") << endl;
}