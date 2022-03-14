/*
 * Created by Xiaozhong on 3/14/2022.
 * Copyright (c) 3/14/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

class Solution {
private:
    const static char LEFT = '(';
    const static char RIGHT = ')';

    void helper(vector<string> &ans, int leftRemain, int rightRemain, string &buffer) {
        if (rightRemain == 0) ans.emplace_back(buffer);
        else {
            if (leftRemain <= rightRemain && leftRemain > 0) {
                buffer.push_back(LEFT);
                helper(ans, leftRemain - 1, rightRemain, buffer);
                buffer.pop_back();
            } else {
                buffer.push_back(RIGHT);
                helper(ans, leftRemain, rightRemain - 1, buffer);
                buffer.pop_back();
                buffer.push_back(LEFT);
                helper(ans, leftRemain - 1, rightRemain, buffer);
                buffer.pop_back();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string buffer;
        helper(ans, n, n, buffer);
        return ans;
    }
};

int main() {
    Solution s;
    auto ret = s.generateParenthesis(3);

}