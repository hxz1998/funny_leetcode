/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;  // 记录有向边，第一维代表出发点，第二维代表可达点
    vector<int> visited;        // =0：未访问；=1：正在访问；=2：访问过了
    bool is_valid = true;       // 全局结果是否合法

    void dfs(int u) {
        visited[u] = 1;             // 先记录下来，代表这个点 u 正在被访问
        for (int v : edges[u]) {    // 挨个遍历检查从 u 出发可达的点 v
            if (visited[v] == 0) {  // 如果 v 没有被访问过，那么就访问一下试试呀~
                dfs(v);             // 访问，然后检查结果是否合法
                if (!is_valid) return;
            } else if (visited[v] == 1) {
                is_valid = false;   // v 已经在访问过程中了，再一次访问，那么说明构成了环，无法拓朴排序
                return;
            }
        }
        visited[u] = 2;             // 访问结束，标记来过~
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const vector<int> &item : prerequisites) {
            edges[item[1]].push_back(item[0]);  // 建立边之间的映射关系，因为 [0] 的前置条件是 [1]，所以要从 [1] 粗发来连 [0]
        }
        for (int i = 0; i < numCourses && is_valid; i++) {
            if (!visited[i]) dfs(i);            // 挨个访问并标记结果
        }
        return is_valid;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    Solution s;
    cout << s.canFinish(2, prerequisites) << endl;
}