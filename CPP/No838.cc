/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        char left = 'L';
        while (i < n) {
            int j = i;
            while (j < n && dominoes[j] == '.') ++j;
            char right = j < n ? dominoes[j] : 'R';
            if (left == right) {
                while (i < j) dominoes[i++] = left;
            } else if(left == 'R' && right == 'L') {
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = left;
                    dominoes[k--] = right;
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};