/**
 * Created by Xiaozhong on 2020/10/4.
 * Copyright (c) 2020/10/4 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
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
*/

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> keyboard = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        unordered_map<char, int> mapper;
        for (int idx = 1; idx <= keyboard.size(); ++idx) {
            for (char c: keyboard[idx - 1]) mapper[c] = idx;
        }
        vector<string> ans;
        for (const string &word: words) {
            int line = mapper[word[0]];
            bool isValid = true;
            for (const char &c: word)
                if (mapper[c] != line) {
                    isValid = false;
                    break;
                }
            if (isValid) ans.emplace_back(word);
        }
        return ans;
    }
};
