/**
 * Created by Xiaozhong on 2020/9/17.
 * Copyright (c) 2020/9/17 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int first = i >= 0 ? num1[i] - '0' : 0;
            int second = j >= 0 ? num2[j] - '0' : 0;
            int sum = first + second + carry;
            carry = sum / 10;
            ans.append(to_string(sum % 10));
            i--, j--;
        }
        if (carry != 0) ans.append(to_string(carry));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.addStrings("123", "456") << endl;
    cout << s.addStrings("1", "9") << endl;
    cout << s.addStrings("99", "9");
}