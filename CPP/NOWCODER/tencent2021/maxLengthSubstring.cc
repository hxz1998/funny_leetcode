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
    int n = 0, k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int left = 0, right = 0, ans = 0;
    unordered_set<char> set;
    while (right < n) {
        while (right < n && set.size() <= k && set.find(s[right]) == set.end()) set.insert(s[right++]);
        ans = max(ans, right - left);
        while (left < right && (set.size() > k || set.find(s[right]) != set.end())) set.erase(s[left++]);
    }
    cout << ans << endl;
}