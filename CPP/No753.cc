/**
 * Created by Xiaozhong on 2020/12/3.
 * Copyright (c) 2020/12/3 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
    unordered_set<int> seen;
    string ans;
    int highest;
    int k;

    void dfs(int node) {
        for (int x = 0; x < k; ++x) {
            int nei = 10 * node + x;
            if (!seen.count(nei)) {
                seen.insert(nei);
                dfs(nei % highest);
                ans += (x + '0');
            }
        }
    }

public:
    string crackSafe(int n, int k) {
        this->k = k;
        highest = pow(10, n - 1);
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.crackSafe(1, 2) << endl;
}