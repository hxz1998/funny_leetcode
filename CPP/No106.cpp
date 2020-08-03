/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */
#include "simple_node.h"
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        post_index = (int) postorder.size() - 1;
        return helper(inorder, postorder, 0, (int) inorder.size() - 1);
    }

private:
    unordered_map<int, int> index;
    int post_index = 0;

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int in_left, int in_right) {
        if (in_left > in_right) return nullptr;
        int root_val = postorder[post_index];
        auto root = new TreeNode(root_val);
        int root_index = index[root_val];
        post_index--;
        root->right = helper(inorder, postorder, root_index + 1, in_right);
        root->left = helper(inorder, postorder, in_left, root_index - 1);
        return root;
    }
};

