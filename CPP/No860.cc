/**
 * Created by Xiaozhong on 2020/12/10.
 * Copyright (c) 2020/12/10 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0;
        for (int cost : bills) {
            if (cost == 5) five++;
            else if (cost == 10) {
                if (five >= 1) {
                    five--;
                    ten++;
                } else return false;
            } else if (cost == 20) {
                if (five >= 1 && ten >= 1) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << s.lemonadeChange(bills) << endl;
    bills = {5, 5, 10, 10, 20};
    cout << s.lemonadeChange(bills) << endl;
}