/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
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

class Solution {
private:
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return false;
        // 对左子树进行检查，看看左子树是否满足（包含 p || 包含 q）
        bool lson = dfs(root->left, p, q);
        // 对右子树进行上述检查
        bool rson = dfs(root->right, p, q);
        // 当左子树满足条件而且右子树满足条件，说明当前节点是他们的 LCA
        // 或者：当前 root 是 p 和 q 中一个节点，而且满足 root 的左右子树中任意一个包含 p 或 q，那么就说明当前节点是 LCA
        if ((rson && lson) || ((root->val == p->val || root->val == q->val) && (rson || lson))) ans = root;
        /*
         * 判断当前节点：
         *  的左子树是否包含 p 或 q
         *  的右子树是否包含 p 或 q
         *  是不是 p 或 q
         */
        return rson || lson || root->val == p->val || root->val == q->val;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};
