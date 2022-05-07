/**
 * Created by Xiaozhong on 2022/4/29.
 * Copyright (c) 2022/4/29 Xiaozhong. All rights reserved.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode *> stk;
    TreeNode *curr;
public:
    BSTIterator(TreeNode *_root) : curr(_root) {
    }

    int next() {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        int ret = curr->val;
        curr = curr->right;
        return ret;
    }

    bool hasNext() {
        return curr != nullptr && !stk.empty();
    }
};