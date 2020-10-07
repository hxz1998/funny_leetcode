/**
 * Created by Xiaozhong on 2020/10/4.
 * Copyright (c) 2020/10/4 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> line = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        vector<string> ans;
        unordered_map<char, int> mapper;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < line[i].length(); ++j) {
                mapper[line[i][j]] = i;
            }
        }
        for (const string &item : words) {
            int index = mapper[item[0]];
            bool flag = true;
            for (int i = 1; i < item.length(); ++i) {
                if (mapper[item[i]] != index) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(item);
        }
        return ans;
    }
};