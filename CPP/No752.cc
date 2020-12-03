/**
 * Created by Xiaozhong on 2020/12/3.
 * Copyright (c) 2020/12/3 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dead;
        dead.insert(deadends.begin(), deadends.end());
        // 检查开始的节点 0000 是否在 deadends 中
        if (dead.count("0000")) return -1;
        int ans = 0;

        // 用于广度优先搜索算法的队列
        queue<string> q;
        // 把开始的节点放进来
        q.push("0000");
        while (!q.empty()) {
            size_t sz = q.size();
            // 逐层遍历
            for (int i = 0; i < sz; ++i) {
                string top_value = q.front();
                q.pop();
                if (top_value == target) return ans;
                for (int j = 0; j < 4; ++j) {
                    for (int k = -1; k <= 1; k += 2) {
                        char y = (top_value[j] - '0' + 10 + k) % 10 + '0';
                        string tmp = top_value;
                        tmp[j] = y;
                        // 如果发现新构造的 tmp 不在 dead 中，那么就把这个数字放进来，同时标记一下，不能重复使用
                        if (!dead.count(tmp)) {
                            q.push(tmp);
                            dead.emplace(tmp);
                        }
                    }
                }
            }
            // 一层过去，可以+1了
            ans++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    cout << s.openLock(deadends, "0202") << endl;
}