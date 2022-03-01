/*
 * Created by Xiaozhong on 3/1/2022.
 * Copyright (c) 3/1/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> table(numRows);
        bool upToDown = false;
        int row = 0;
        for (int idx = 0; idx < s.length(); ++idx) {
            if (row == numRows - 1 || row == 0) upToDown = !upToDown;
            table[row].push_back(s[idx]);
            if (upToDown) row++;
            else row--;
        }
        string ans;
        for (int r = 0; r < numRows; ++r) ans.append(table[r]);
        return ans;
    }
};