/**
 * Created by Xiaozhong on 2020/8/18.
 * Copyright (c) 2020/8/18 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    vector<int> ans;

    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) dfs(root->left);
        ans.push_back(root->val);
        if (root->right) dfs(root->right);
    }

    int index = 0;

public:
    BSTIterator(TreeNode *root) {
        dfs(root);
    }

    /** @return the next smallest number */
    int next() {
        if (index < ans.size()) {
            return ans[index++];
        }
        return -1;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < ans.size();
    }
};
