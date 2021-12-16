/*
 * Created by Xiaozhong on 12/10/2021.
 * Copyright (c) 12/10/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty()) return false;
        return check(postorder, 0, postorder.size());
    }

private:
    bool check(vector<int> &postorder, int left, int right) {
        if (right - left == 0) return true;
        int root = postorder[right - 1];
        int leftSub = 0;
        while (leftSub < right - 1) {
            if (postorder[leftSub++] > root) break;
        }
        int rightSub = leftSub;
        while (rightSub < right) {
            if (postorder[rightSub++] < root) return false;
        }
        bool leftValid = true;
        if (leftSub > 0) leftValid = check(postorder, left, leftSub);
        bool rightValid = true;
        if (leftSub < right) rightValid = check(postorder, leftSub, right - 1);
        return leftValid && rightValid;
    }
};

int main() {
    vector<int> postorder = {4, 6, 12, 8, 16, 14, 10};
    Solution s;
    cout << s.verifyPostorder(postorder);
}