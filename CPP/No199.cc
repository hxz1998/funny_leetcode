/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode *root, int depth) {
        if (!root) return;
        if (ans.size() == depth) ans.push_back(root->val);  // 当深度和数组大小一致时，说明当前根节点的数值还没有添加进来
        depth++;    // 更新深度
        if (root->right) dfs(root->right, depth);           // 先访问右节点，再放问左节点，会保证得到一个右视图
        if (root->left) dfs(root->left, depth);
    }

public:
    vector<int> rightSideView(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }
};