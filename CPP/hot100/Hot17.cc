/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> mapper{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        string buffer;
        backtrack(ans, buffer, 0, digits, mapper);
        return ans;
    }

private:
    void backtrack(vector<string> &combinations, string &buffer, int idx, const string &digits,
                   const unordered_map<char, string> &mapper) {
        if (idx == digits.size()) {
            combinations.emplace_back(buffer);
        } else {
            char digit = digits[idx];
            for (const char &letter: mapper.at(digit)) {
                buffer.push_back(digit);
                backtrack(combinations, buffer, idx + 1, digits, mapper);
                buffer.pop_back();
            }
        }
    }
};