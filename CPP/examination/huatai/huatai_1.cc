/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 方法一
//class Solution {
//public:
//
//    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
//        if (t1 != nullptr && t2 != nullptr) {
//            t1->val += t2->val;
//            t1->left = mergeTrees(t1->left, t2->left);
//            t1->right = mergeTrees(t1->right, t2->right);
//            return t1;
//        } else if (t1 == nullptr && t2 != nullptr) {
//            return t2;
//        } else if (t1 != nullptr && t2 == nullptr) {
//            return t1;
//        } else return nullptr;
//    }
//};

class Solution {
public:
    /**
     * 递归的方法，让 t2 合并到 t1 上来
     * 如果 双方都不为 空，那么就合并值
     * 否则将非空的一方直接返回，拼接在父节点上
     */
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 != nullptr && t2 != nullptr) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        } else if (t1 == nullptr && t2 != nullptr) {
            return t2;
        } else if (t1 != nullptr && t2 == nullptr) {
            return t1;
        } else return nullptr;
    }
};