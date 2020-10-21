/**
 * Created by Xiaozhong on 2020/10/19.
 * Copyright (c) 2020/10/19 Xiaozhong. All rights reserved.
 */
#include <queue>
#include <iostream>

using namespace std;

class Node {
    int val;
public:
    Node(int _val) : val(_val) {}

    // 重写 < 运算符，这样用来比较两个元素的优先级，less 函数调用
    friend bool operator<(const Node &lhs, const Node &rhs) {
        return lhs.val < rhs.val;
    }

    // 重写 > 运算符，greater 函数调用
    friend bool operator>(const Node &lhs, const Node &rhs) {
        return lhs.val > rhs.val;
    }

    const string toString() const { return to_string(val); }
};

int main() {

    class cmp {
    public :
        bool operator()(const int a, const int b) {
            return a % 10 > b % 10;
        };
    };

    // 个位数 大的 优先级反而小
    priority_queue<int, vector<int>, cmp> int_pq;
    for (int i = 0; i < 20; ++i) int_pq.push(i);
    for (int i = 0; i < 20; ++i) {
        cout << int_pq.top() << " ";
        int_pq.pop();
    }
    // >: 10 1 11 12 2 3 13 14 4 15 5 6 16 7 17 8 18 9 19
    cout << endl;

    priority_queue<Node> node_pq;
    for (int i = 0; i < 20; ++i) node_pq.push(Node(i));
    for (int i = 0; i < 20; ++i) {
        cout << node_pq.top().toString() << " ";
        node_pq.pop();
    }
    // >: 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
    cout << endl;

    // 使用 greater 来让数值越小优先级越大
    priority_queue<Node, vector<Node>, greater<Node>> rev_pq;
    for (int i = 0; i < 20; ++i) rev_pq.push(Node(i));
    for (int i = 0; i < 20; ++i) {
        cout << rev_pq.top().toString() << " ";
        rev_pq.pop();
    }
    // >: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
}

