/**
 * Created by Xiaozhong on 2022/3/11.
 * Copyright (c) 2022/3/11 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    vector<string> split(const string &str, const char &delimiter) {
        vector<string> ret;
        string buffer;
        for (const char &c: str) {
            if (c == delimiter) {
                ret.emplace_back(buffer);
                buffer.clear();
            } else {
                buffer.push_back(c);
            }
        }
        if (!buffer.empty()) ret.emplace_back(buffer);
        return ret;
    }

public:
    // 层序遍历
    string serialize(TreeNode *root) {
        queue<TreeNode *> q;
        string ret;
        if (nullptr == root) return ret;
        q.push(root);
        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            for (int idx = 0; idx < sz; ++idx) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) ret.append("#,");
                else {
                    ret.append(to_string(node->val).append(","));
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        ret.pop_back();
        return ret;
    }

    TreeNode *deserialize(string data) {
        if (data.size() == 0) return nullptr;
        vector<string> ret = split(data, ',');
        int n = static_cast<int>(ret.size());
        TreeNode *root = new TreeNode(stoi(ret[0]));
        queue<TreeNode *> q;
        q.push(root);
        int idx = 1;
        while (idx < n) {
            int sz = static_cast<int>(q.size());
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (ret[idx] != "#") {
                    node->left = new TreeNode(stoi(ret[idx]));
                    q.push(node->left);
                }
                idx++;
                if (ret[idx] != "#") {
                    node->right = new TreeNode(stoi(ret[idx]));
                    q.push(node->right);
                }
                idx++;
            }
        }
        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec coder;
    cout << coder.serialize(root) << endl;
    coder.deserialize("1,2,3,#,#,4,5,#,#,#,#");
}