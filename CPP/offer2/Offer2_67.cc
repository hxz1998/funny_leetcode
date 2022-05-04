/**
 * Created by Xiaozhong on 2022/5/4.
 * Copyright (c) 2022/5/4 Xiaozhong. All rights reserved.
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

class Solution {
    struct Trie {
        // 规定左边是 0，右边是 1
        Trie *left, *right;
    };

    void add(int num) {
        Trie *curr = root;
        for (int offset = HIGH_BIT; offset >= 0; --offset) {
            int bit = (num >> offset) & 1;
            if (bit == 0) {
                if (curr->left == nullptr) curr->left = new Trie();
                curr = curr->left;
            } else {
                if (curr->right == nullptr) curr->right = new Trie();
                curr = curr->right;
            }
        }
    }

    int check(int num) {
        Trie *curr = root;
        int ret = 0;
        for (int offset = HIGH_BIT; offset >= 0; --offset) {
            int bit = (num >> offset) & 1;
            if (bit == 0) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                    ret = (ret << 1) | 1;
                } else {
                    curr = curr->left;
                    ret = (ret << 1);
                }
            } else {
                if (curr->left != nullptr) {
                    curr = curr->left;
                    ret = (ret << 1) | 1;
                } else {
                    curr = curr->right;
                    ret = (ret << 1);
                }
            }
        }
        return ret;
    }

public:
    int findMaximumXOR(vector<int> &nums) {
        int ans = 0;
        for (int idx = 1; idx < nums.size(); ++idx) {
            add(nums[idx - 1]);
            ans = max(ans, check(nums[idx]));
        }
        return ans;
    }

private:

    Trie *root = new Trie();
    static const int HIGH_BIT = 30;
};