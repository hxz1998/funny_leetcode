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

class Bank {
private:
    int n = 0;
    vector<long long> balance;
public:
    Bank(vector<long long> &_balance) : balance(_balance) {
        n = static_cast<int>(balance.size());
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 > n || account2 <= 0 || account2 > n) return false;
        if (balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        long long origin = balance[account2 - 1];
        long long _money = origin + money;
        if (_money < origin) return false;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account <= 0 || account > n) return false;
        long long origin = balance[account - 1];
        long long _money = origin + money;
        if (_money < origin) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account <= 0 || account > n) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};