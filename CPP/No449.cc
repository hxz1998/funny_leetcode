/**
 * Created by Xiaozhong on 2020/9/24.
 * Copyright (c) 2020/9/24 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "string"
#include "queue"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
private:
    deque<int> split(string s) {
        deque<int> ans;
        string buf = "";
        for (char c : s) {
            if (c != ' ') buf.push_back(c);
            else if (buf.length() != 0) {
                ans.push_back(stoi(buf));
                buf = "";
            }
        }
        if (!buf.empty()) ans.push_back(stoi(buf));
        return ans;
    }

    void postorder(TreeNode *root, string &s) {
        if (root == nullptr) return;
        postorder(root->left, s);
        postorder(root->right, s);
        s.append(to_string(root->val));
        s.append(" ");
    }

    TreeNode *helper(int lower, int upper, deque<int> &nums) {
        if (nums.empty()) return nullptr;
        int val = nums.back();
        if (val < lower || val > upper) return nullptr;
        nums.pop_back();
        TreeNode *node = new TreeNode(val);
        node->right = helper(val, upper, nums);
        node->left = helper(lower, val, nums);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans;
        postorder(root, ans);
        return ans.substr(0, ans.length() - 1);
    }


    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;
        deque<int> dq = split(data);
        return helper(INT32_MIN, INT32_MAX, dq);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    Codec c;
    string ans = c.serialize(root);
    cout << ans << endl;
    c.deserialize(ans);
}