/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string revs = s;                        //存s的逆序
        int tn = s.size();                      //中点处,#前面的位置
        reverse(revs.begin(), revs.end());
        s = ' ' + s + '#' + revs;               //让下标从1开始
        int n = s.size() - 1;                   //实际长度
        vector<int> ne(n + 1);                  //next数组
        for (int i = 2, j = 0; i <= n; i++) {   //求next数组
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        return s.substr(tn + 2, tn - ne[n]) + s.substr(1, tn);  //后半部分除去重叠后缀+前半部分
    }
};