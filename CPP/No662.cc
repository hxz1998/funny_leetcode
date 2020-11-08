/**
 * Created by Xiaozhong on 2020/11/8.
 * Copyright (c) 2020/11/8 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct AnnoationNode {
    int depth, pos;
    TreeNode *node = nullptr;

    AnnoationNode(TreeNode *n, int d, int p) : depth(d), pos(p), node(n) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        queue<AnnoationNode *> q;
        q.push(new AnnoationNode(root, 0, 0));
        int curDepth = 0, left = 0, ans = 0;
        while (!q.empty()) {
            AnnoationNode *a = q.front();
            q.pop();
            if (a->node != nullptr) {
                q.push(new AnnoationNode(a->node->left, a->depth + 1, 2 * a->pos));
                q.push(new AnnoationNode(a->node->right, a->depth + 1, 2 * a->pos + 1));
                if (curDepth != a->depth) {
                    curDepth = a->depth;
                    left = a->pos;
                }
                ans = max(ans, a->pos - left + 1);
            }
        }
        return ans;
    }
};

int main() {

}