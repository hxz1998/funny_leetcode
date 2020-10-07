/**
 * Created by Xiaozhong on 2020/7/23.
 * Copyright (c) 2020/7/23 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 该题拷贝的别人的答案
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> realPath;

        stringstream ss(path);
        string token;
        vector<string> tokens;
        // 这种方法可以丢掉最后一个 空token, 但是第一个token 不能丢掉
        while (getline(ss, token, '/')) {
            if (token == "") continue; // 删除不合法的 token
            tokens.push_back(token);
        }

        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (realPath.size() > 0) {
                    realPath.pop_back();
                }
            } else {
                realPath.push_back(token);
            }
        }

        string ans = "";
        for (auto &item: realPath) {
            ans.push_back('/');
            ans += item;
        }
        return ans == "" ? "/" : ans;
    }
};