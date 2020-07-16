/**
 * Created by Xiaozhong on 2020/7/16.
 * Copyright (c) 2020/7/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> res(num1.length() + num2.length());
        for (int i = num1.length() - 1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            for (int j = num2.length() - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = (res[i + j + 1] + n1 * n2);
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string ans = "";
        for (int k = 0; k < res.size(); ++k) {
            if (k == 0 && res[k] == 0) continue;
            ans.append(to_string(res[k]));
        }
        return ans;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    cout << s.multiply("3", "4") << endl;
}