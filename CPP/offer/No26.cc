/**
 * Created by Xiaozhong on 2021/12/5.
 * Copyright (c) 2021/12/5 Xiaozhong. All rights reserved.
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
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr && A != nullptr) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool dfs(TreeNode *lhs, TreeNode *rhs) {
        if (rhs == nullptr) return true;
        if (lhs == nullptr) return false;
        if (rhs->val != lhs->val) return false;
        return dfs(lhs->left, rhs->left) && dfs(lhs->right, rhs->right);
    }
};

int main() {

}