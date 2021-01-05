/**
 * Created by Xiaozhong on 2020/12/26.
 * Copyright (c) 2020/12/26 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        queue<int> student_queue;
        stack<int> sandwiches_stack;
        for (int s : students) student_queue.push(s);
        for (auto iter = sandwiches.rbegin(); iter != sandwiches.rend(); ++iter)
            sandwiches_stack.push(*iter);
        while (true) {
            int i = 0;
            for (; i < student_queue.size(); ++i) {
                if (sandwiches_stack.top() == student_queue.front()) {
                    sandwiches_stack.pop();
                    student_queue.pop();
                    if (student_queue.size() == 1) return student_queue.front() != sandwiches_stack.top();
                    break;
                } else {
                    student_queue.push(student_queue.front());
                    student_queue.pop();
                }
            }
            if (i == student_queue.size()) return student_queue.size();
        }
        return student_queue.size();
    }
};

int main() {
    Solution s;
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << s.countStudents(students, sandwiches) << endl;
    students = {1, 1, 1, 0, 0, 1};
    sandwiches = {1, 0, 0, 0, 1, 1};
    cout << s.countStudents(students, sandwiches) << endl;
    students = {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1};
    sandwiches = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0};
    cout << s.countStudents(students, sandwiches) << endl;
}