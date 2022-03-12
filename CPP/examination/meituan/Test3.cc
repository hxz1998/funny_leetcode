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
    int m = 0, n = 0;
    cin >> m >> n;
    function<bool(int)> check = [](int num) {
        int tmp = 0;
        int rec = num;
        while (num != 0) {
            tmp += pow(num % 10, 3);
            num /= 10;
        }
        return tmp == rec;
    };
    vector<int> buffer;
    for (int num = m; num <= n; ++num) {
        if (check(num)) buffer.emplace_back(num);
    }
    if (buffer.empty()) cout << "no" << endl;
    for (int idx = 0; idx < buffer.size(); ++idx) {
        if (idx == buffer.size() - 1) cout << buffer[idx];
        else cout << buffer[idx] << " ";
    }
    return 0;
}