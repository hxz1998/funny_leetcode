/**
 * Created by Xiaozhong on 2020/10/30.
 * Copyright (c) 2020/10/30 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> counter(26, 0);
        for (const char &c : tasks) ++counter[c - 'A'];
        sort(counter.begin(), counter.end());
        int ans = 0;
        while (counter[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (counter[25] <= 0) break;
                if (i < 26 && counter[25 - i] > 0) counter[25 - i]--;
                ++ans;
                ++i;
            }
            sort(counter.begin(), counter.end());
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2);
}