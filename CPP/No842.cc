/**
 * Created by Xiaozhong on 2020/12/8.
 * Copyright (c) 2020/12/8 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool backtrack(vector<int> &list, const string &s, size_t length, size_t idx, size_t sum, size_t prev) {
        if (idx == length) return list.size() >= 3;
        long long curr = 0;
        for (int i = idx; i < length; ++i) {
            if (i > idx && s[idx] == '0') break;
            curr = curr * 10 + s[i] - '0';
            if (curr > INT32_MAX) break;
            if (list.size() >= 2) {
                if (curr < sum) {
                    continue;
                } else if (curr > sum) {
                    break;
                }
            }
            list.emplace_back(curr);
            if (backtrack(list, s, length, i + 1, prev + curr, curr)) {
                return true;
            } else {
                list.pop_back();
            }
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.splitIntoFibonacci("214748364721474836422147483641");
    return 0;
}