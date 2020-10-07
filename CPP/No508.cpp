/**
 * Created by Xiaozhong on 2020/10/7.
 * Copyright (c) 2020/10/7 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> counter;

    // 深度优先搜索
    int dfs(TreeNode *root) {
        if (!root) return 0;
        // 当前节点的和 = 当前节点的值 + 左子树节点和 + 右子树节点和
        int sum = root->val + dfs(root->left) + dfs(root->right);
        // 对出现的 和 进行统计计数
        ++counter[sum];
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        dfs(root);
        vector<int> ans;
        int max_num = 0;    // 用来记录到底哪个 出现的次数 是最大值
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) max_num = max(max_num, iter->second);
        for (auto iter = counter.begin(); iter != counter.end(); ++iter)
            // 如果和最大值相对应，那么就放到返回值中
            if (iter->second == max_num) ans.push_back(iter->first);
        return ans;
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    Solution s;
    vector<int> ans = s.findFrequentTreeSum(root);
    for (int item : ans) {
        cout << item << endl;
    }
}