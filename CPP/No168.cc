/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */

#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n != 0) {
            n--;
            ans.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};