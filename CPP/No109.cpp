/**
 * Created by Xiaozhong on 2020/8/3.
 * Copyright (c) 2020/8/3 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        while (head) {
            v_nums.push_back(head->val);
            head = head->next;
        }
        return dfs(0, (int) v_nums.size() - 1, v_nums);
    }

private:
    vector<int> v_nums;

    TreeNode *dfs(int left, int right, vector<int> &nums) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(left, mid - 1, nums);
        root->right = dfs(mid + 1, right, nums);
        return root;
    }
};