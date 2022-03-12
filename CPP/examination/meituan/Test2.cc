/**
 * Created by Xiaozhong on 2022/3/12.
 * Copyright (c) 2022/3/12 Xiaozhong. All rights reserved.
 */

#include <iomanip>
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "cmath"

using namespace std;

int main() {
    double n = 0;
    int m = 0;
    cin >> n >> m;
    double ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += n;
        n = sqrt(n);
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}