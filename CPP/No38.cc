/**
 * Created by Xiaozhong on 2020/7/15.
 * Copyright (c) 2020/7/15 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "";
        int pl = 0;
        int cur = 1;
        string str = countAndSay(n - 1);
        for (cur = 1; cur < str.length(); cur++) {
            if (str[cur] != str[pl]) {
                int count = cur - pl;
                ans.append(to_string(count));
                ans.append(to_string(str[pl] - '0'));
                pl = cur;
            }
        }
        if (pl != cur) {
            int count = cur - pl;
            ans.append(to_string(count));
            ans.append(to_string(str[pl] - '0'));
        }
        return ans;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    cout << s.countAndSay(5) << endl;
    map<string, int> mapper;
    mapper["a"] = 1;
    mapper["b"] = 2;
    mapper["a"] = 3;
    string tmp;
    for (std::map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++) {
        tmp += to_string(mapper[it->first]);
        tmp += it->first;
    }
    cout << tmp << endl;
}
