/**
 * Created by Xiaozhong on 2020/10/19.
 * Copyright (c) 2020/10/19 Xiaozhong. All rights reserved.
 */

#include <set>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int coeff[3] = {2, 3, 5};
/**
 * 求第 1500 个丑数
 * 1, 2, 3, 5, 6, 8...
 */
int main() {
    // 把丑数从小到大排序
    priority_queue<LL, vector<LL>, greater<>> pq;
    // 丑数集合
    set<LL> s;
    // 初始值放进来
    pq.push(1);
    s.insert(1);
    for (int i = 1;; ++i) {
        LL x = pq.top();
        pq.pop();
        if (i == 1500) {
            cout << "The 1500`th ugly number is " << x << "." << endl;
            break;
        }
        for (int j = 0; j < 3; ++j) {
            LL x2 = x * coeff[j];
            if (!s.count(x2)) {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
}