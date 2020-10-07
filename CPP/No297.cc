/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include <sstream>
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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur == nullptr) {
                    res += "-.";
                } else {
                    string str_val = to_string(cur->val) + ".";
                    res += str_val;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream s(data);   // 使用stringstream来使用高阶函数
        string str_node;
        queue<TreeNode *> que;
        getline(s, str_node, '.');  // 从 s 中，按照 . 来分割一个字符串出来，存到 str_node 中
        TreeNode *root;
        if (str_node == "-") {  // 第一个节点就是空的
            return nullptr;
        } else {                // 第一个节点不为空，那么就把它填充好，并且加入队列
            int inte_node = stoi(str_node);
            root = new TreeNode(inte_node);
            que.push(root);
        }
        while (!que.empty()) {  // 开始 广度优先算法 填充每一个节点
            int siz = que.size();
            while (siz--) {
                TreeNode *cur = que.front();    // 从左向右挨个填充
                que.pop();
                if (cur != nullptr) {           // 如果不为空的节点，那么就看看能不能填充它的左右子结点
                    string str_left, str_right;
                    if (getline(s, str_left, '.') && str_left != "-") { // 获取左边子结点的数据
                        TreeNode *l = new TreeNode(stoi(str_left));
                        que.push(l);
                        cur->left = l;
                    }
                    if (getline(s, str_right, '.') && str_right != "-") {// 获取右边子节点的数据
                        TreeNode *r = new TreeNode(stoi(str_right));
                        que.push(r);
                        cur->right = r;
                    }
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));