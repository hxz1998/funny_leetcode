/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "unordered_map"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int> &rounds) {
        unordered_map<int, int> mapper;
        vector<int> ans;
        int max_rounds = 0;
        for (int i = 0; i < n; i++) mapper[i + 1] = 0;
        for (int i = 0; i < rounds.size() - 1; i++) {
            int start = rounds[i];
            int end = rounds[i + 1];
            for (int j = start;; j++) {
                if (j > n) j = j % n;
                mapper[j]++;
                max_rounds = max(max_rounds, mapper[j]);
                if (j == end) break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (mapper[i] == max_rounds) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    vector<int> rounds = {1, 3, 1, 2};
    Solution s;
    vector<int> ans = s.mostVisited(4, rounds);
    for (int i : ans) {
        cout << i << " ";
    }
}