/**
 * Created by Xiaozhong on 2022/3/12.
 * Copyright (c) 2022/3/12 Xiaozhong. All rights reserved.
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

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    auto check = [](int num) {
        int cnt = 0;
        while (num > 0) {
            if (num % 10 == 1) cnt++;
            num /= 10;
        }
        return cnt >= 2;
    };
    while (n-- > 0) {
        int num = 0;
        cin >> num;
        if (num % 11 == 0 || check(num)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

