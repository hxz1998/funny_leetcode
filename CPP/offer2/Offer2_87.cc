/**
 * Created by Xiaozhong on 2022/4/2.
 * Copyright (c) 2022/4/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    void backtrack(vector<string> &ans, string &buffer, string &str, int start, int remain,
                   function<bool(const string &, int, int)> check) {
        if (remain == -1 && buffer.size() == str.size() + 4) {
            buffer.pop_back();
            ans.push_back(buffer);
            return;
        }
        if (remain < 0 || remain == 0 && str.size() - start > 3) return;
        int n = static_cast<int>(str.size());
        for (int i = start; i < start + 3 && i < n; ++i) {
            if (check(str, start, i)) {
                string rec = buffer;
                buffer.append(str.substr(start, i - start + 1)).append(".");
                backtrack(ans, buffer, str, i + 1, remain - 1, check);
                buffer = rec;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string buffer;
        function<bool(const string &str, int, int)> check = [](const string &str, int begin, int end) {
            int num = 0;
            for (int idx = begin; idx <= end; ++idx) {
                if (idx == begin + 1 && str[idx - 1] == '0') return false;
                num = num * 10 + (str[idx] - '0');
            }
            return num <= 255;
        };
        backtrack(ans, buffer, s, 0, 3, check);
        return ans;
    }
};

int main() {
    Solution s;
    s.restoreIpAddresses("25525511135");
}