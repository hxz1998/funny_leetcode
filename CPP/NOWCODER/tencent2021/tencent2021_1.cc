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

class MyUnionFind {
private:
    vector<int> parents;
    vector<int> counter;
public:
    MyUnionFind(int size) {
        parents = vector<int>(size + 1);
        for (int idx = 0; idx < parents.size(); ++idx) parents[idx] = idx;
        counter = vector<int>(size + 1, 1);
    }

    int find(int node) {
        while (node != parents[node]) {
            parents[node] = find(parents[node]);
            node = parents[node];
        }
        return node;
    }

    // 右边接到左边
    void connect(int lhs, int rhs) {
        int lhsParent = find(lhs);
        int rhsParent = find(rhs);
        if (lhsParent == rhsParent) return;
        parents[rhsParent] = lhsParent;
        counter[lhs] += counter[rhsParent];
    }

    int maxSize() {
        int ret = 0;
        for (int idx = 0; idx < counter.size(); ++idx) ret = max(ret, counter[idx]);
        return ret;
    }
};

int main() {
    int T = 0;
    cin >> T;
    while (T-- > 0) {
        int n = 0;
        cin >> n;
        MyUnionFind uf(1e6);
        while (n-- > 0) {
            int lhs = 0, rhs = 0;
            cin >> lhs >> rhs;
            uf.connect(lhs, rhs);
        }
        cout << uf.maxSize() << endl;
    }
}