/**
 * Created by Xiaozhong on 2020/12/27.
 * Copyright (c) 2020/12/27 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int n = apples.size();
        int ans = 0, i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({days[0], apples[0]});
        while (!pq.empty() || i < n) {
            while (!pq.empty() && (pq.top().first <= i || pq.top().second <= 0)) pq.pop();
            if (!pq.empty()) {
                auto t = pq.top();
                pq.pop();
                pq.push({t.first, t.second - 1});
                ans++;
            }
            i++;
            if (i < n) pq.push({i + days[i], apples[i]});
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> apples = {1, 2, 3, 5, 2};
    vector<int> days = {3, 2, 1, 4, 2};
    cout << s.eatenApples(apples, days) << endl;
    apples = {0, 3, 0, 0, 0, 0, 2};
    days = {0, 3, 0, 0, 0, 0, 2};
    cout << s.eatenApples(apples, days) << endl;
    apples = {9, 24, 5, 12, 15, 21, 13, 12, 28, 0, 21, 6, 0, 26, 20, 0, 21, 21, 7, 0, 19, 25, 0, 30, 32, 32, 0, 0, 0,
              22, 0, 11, 2, 27, 16, 0, 15, 12, 14, 33, 10, 11, 0, 13, 11, 0, 27, 0, 0, 14, 20, 11, 0, 22, 10, 1, 22, 6,
              0, 13, 31, 33, 30, 27, 2, 30, 18};
    days = {3, 48, 2, 21, 20, 13, 25, 9, 20, 0, 34, 6, 0, 33, 38, 0, 42, 24, 9, 0, 20, 38, 0, 30, 52, 22, 0, 0, 0, 27,
            0, 22, 2, 53, 8, 0, 10, 18, 1, 62, 20, 15, 0, 9, 13, 0, 28, 0, 0, 24, 2, 2, 0, 9, 3, 2, 1, 2, 0, 15, 46, 58,
            37, 12, 1, 28, 29};
    cout << s.eatenApples(apples, days) << endl;
}