/**
 * Created by Xiaozhong on 2022/3/18.
 * Copyright (c) 2022/3/18 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.size()) - 1;
        function<bool(const string &, int, int)> check = [](const string &s, int left, int right) {
            while (left < right && s[left] == s[right]) {
                left++;
                right--;
            }
            if (left == right || left - right == 1) return true;
            return false;
        };
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        if (left == right || left - right == 1) return true;
        if (check(s, left, right - 1) || check(s, left + 1, right)) return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("abc");
}