/**
 * Created by Xiaozhong on 2020/7/24.
 * Copyright (c) 2020/7/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int k, n;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> buffer;
        backtrack(1, buffer);
        return ans;
    }

private:
    void backtrack(int first, vector<int> &buffer) {
        if (buffer.size() == k) {
            ans.push_back(buffer);
        }
        for (int i = first; i <= n; i++) {
            buffer.push_back(i);
            backtrack(i + 1, buffer);
            buffer.pop_back();
        }
    }
};

int main() {

}