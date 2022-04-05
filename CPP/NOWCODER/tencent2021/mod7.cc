/**
 * Created by Xiaozhong on 2022/3/24.
 * Copyright (c) 2022/3/24 Xiaozhong. All rights reserved.
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

int main() {
    int n = 0;
    cin >> n;
    int pos = 0;
    while (pos <= n) {
        int high = 0, low = 0;
        if (pos == 0) {
            high = n;
            low = 0;
        } else {
            high = n / (int) pow(10, pos);
            low = n % (int) pow(10, pos);
        }
        for (int insertVal = 0; insertVal <= 9; ++insertVal) {
            int tmp = high * 10 + insertVal * pow(10, pos) + low;
            if (tmp % 7 == 0) {
                cout << tmp << endl;
                return 0;
            }
        }
        pos++;
    }
}