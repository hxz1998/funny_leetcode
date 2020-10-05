/**
 * Created by Xiaozhong on 2020/10/5.
 * Copyright (c) 2020/10/5 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
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
    // 使用哈希表来对每一个出现的数字进行统计
    unordered_map<int, int> mapper;

    // 深度优先遍历，统计数字出现的次数
    void dfs(TreeNode *root) {
        if (!root) return;
        ++mapper[root->val];
        dfs(root->left);
        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode *root) {
        // 边界条件
        if (!root) return {};
        dfs(root);

        // 转换成 vector 类型，用于排序，排序时按照 iter->second 从大到小排序（出现次数从高到低）
        vector<pair<int, int>> counter;
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            counter.push_back(make_pair(iter->first, iter->second));
        }
        sort(counter.begin(), counter.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        // 对最终答案进行统计
        vector<int> ans;
        // 首先记录最多次出现的次数是多少
        int times = counter[0].second;
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            // 碰到了不是最多次出现的次数，那么就直接返回 ans
            if (iter->second != times) return ans;
            // 否则就把这个数放到返回值中
            ans.push_back(iter->first);
        }
        return ans;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> ans = s.findMode(root);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}

