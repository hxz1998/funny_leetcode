/**
 * Created by Xiaozhong on 2022/4/27.
 * Copyright (c) 2022/4/27 Xiaozhong. All rights reserved.
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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *ans = nullptr;
    bool isNext = false;
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr) return nullptr;
        if (ans != nullptr) return ans;
        inorderSuccessor(root->left, p);
        if (isNext) {
            ans = root;
            isNext = false;
        }
        if (root == p) isNext = true;
        inorderSuccessor(root->right, p);
        return ans;
    }
};