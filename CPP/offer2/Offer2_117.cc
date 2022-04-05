/**
 * Created by Xiaozhong on 2022/3/19.
 * Copyright (c) 2022/3/19 Xiaozhong. All rights reserved.
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

using namespace std;

class Solution {
private:
    vector<int> index;
    int size;

    inline bool connected(const int &lhs, const int &rhs) {
        return index[lhs] == index[rhs];
    }

    inline int find(int node) {
        while (node != index[node]) {
            node = index[node];
        }
        return index[node];
    }

    // rhs 连接到 lhs 上
    inline void connect(const int &lhs, const int &rhs) {
        size--;
        int root = index[lhs];
        int node = find(rhs);
        for (int idx = 0; idx < index.size(); ++idx) {
            if (index[idx] == node) index[idx] = root;
        }
    }

    // 判断两个是不是可以构成一组
    bool attachable(const string &lhs, const string &rhs) {
        int diff = 0;
        for (int i = 0, size = lhs.size(); i < size; ++i) {
            if (lhs[i] != rhs[i]) {
                ++diff;
            }
            if (diff > 2) {
                return false;
            }
        }
        return diff <= 2;
    }

public:

    int numSimilarGroups(vector<string> &strs) {
        int n = 0;
        n = size = static_cast<int>(strs.size());
        index = vector<int>(size);
        for (int idx = 0; idx < n; ++idx) index[idx] = idx;
        for (int left = 0; left < n - 1; ++left) {
            for (int right = left + 1; right < n; ++right) {
                if (attachable(strs[left], strs[right])) connect(left, right);
            }
        }
        return size;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"kccomwcgcs", "socgcmcwkc", "sgckwcmcoc", "coswcmcgkc", "cowkccmsgc", "cosgmccwkc",
                           "sgmkwcccoc", "coswmccgkc", "kowcccmsgc", "kgcomwcccs"};
    cout << s.numSimilarGroups(strs) << endl;
}