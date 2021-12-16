/*
 * Created by Xiaozhong on 12/13/2021.
 * Copyright (c) 12/13/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string number = to_string(num);
        vector<int> cnt(number.size());
        for (int i = number.size() - 1; i >= 0; --i) {
            if (i == number.size() - 1) cnt[i] = 1;
            else if (i == number.size() - 2) {
                int v = (number[i] - '0') * 10 + number[i + 1] - '0';
                cnt[i] = v <= 25 && v >= 10 ? 2 : 1;
            } else {
                int v = (number[i] - '0') * 10 + number[i + 1] - '0';
                cnt[i] = cnt[i + 1] + (v <= 25 && v >= 10 ? 1 : 0) * cnt[i + 2];
            }
        }
        return cnt[0];
    }
};

int main() {
    Solution s;
    cout << s.translateNum(12258) << endl;
}