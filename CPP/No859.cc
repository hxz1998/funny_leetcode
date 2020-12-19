/**
 * Created by Xiaozhong on 2020/12/19.
 * Copyright (c) 2020/12/19 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A == B) {
            vector<int> count(26, 0);
            for (char c : A) count[c - 'a']++;
            for (int i : count) if (i > 1) return true;
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < A.length(); ++i) {
                if (A[i] != B[i]) {
                    if (first == -1) first = i;
                    else if (second == -1) second = i;
                    else return false;
                }
            }
            return A[first] == B[second] && A[second] == B[first];
        }
    }
};