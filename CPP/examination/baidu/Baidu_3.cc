/**
 * Created by Xiaozhong on 2022/4/19.
 * Copyright (c) 2022/4/19 Xiaozhong. All rights reserved.
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
    unsigned long long ans = 0;
    for (int idx = 0; idx < n; ++idx) {
        int num = 0;
        cin >> num;
        ans += num;
    }
    cout << ans << endl;
}