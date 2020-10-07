/**
 * Created by Xiaozhong on 2020/8/2.
 * Copyright (c) 2020/8/2 Xiaozhong. All rights reserved.
 */
#include "simple_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};