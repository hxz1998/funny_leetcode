/**
 * Created by Xiaozhong on 2021/12/5.
 * Copyright (c) 2021/12/5 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;
        int push = 0, pop = 0;
        while (push != pushed.size() || pop != popped.size()) {
            if (push == pushed.size() && stk.top() != popped[pop]) return false;
            while (stk.empty() || push < pushed.size() && popped[pop] != stk.top()) stk.push(pushed[push++]);
            while (!stk.empty() && pop < popped.size() && stk.top() == popped[pop]) {
                stk.pop();
                pop++;
            }
        }
        return true;
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    Solution s;
    cout << s.validateStackSequences(pushed, popped) << endl;
    pushed = {1, 2, 3, 4 ,5};
    popped = {4, 3, 5, 1, 2};
    cout << s.validateStackSequences(pushed, popped) << endl;
    pushed = {1, 0, 2};
    popped = {2, 1, 0};
    cout << s.validateStackSequences(pushed, popped) << endl;
}