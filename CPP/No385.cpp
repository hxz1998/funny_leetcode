/**
 * Created by Xiaozhong on 2020/9/8.
 * Copyright (c) 2020/9/8 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "stack"

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        int n = s.size();
        if (n == 0) return NestedInteger();
        // 检查边界情况，如果第一个并不是 [ ，那么就说明直接是数字开始
        if (s[0] != '[') return NestedInteger(stoi(s));
        // 否则就构造序列
        string num;
        stack<NestedInteger> st;
        for (int i = 0; i < n; ++i) {
            // 从第一个开始，如果是 [ ，那么就构造一个空的 NestedInteger 放进来，准备添加数据进去
            if (s[i] == '[') st.push(NestedInteger());
            else if (s[i] == ',') { // 如果是 , 那么说明一个数据构造完成了，需要把它添加进栈顶 NestedInteger 中
                if (!num.empty()) st.top().add(NestedInteger(stoi(num)));
                num.clear();
            } else if (s[i] == ']') { // 如果是 ] 那么说明遇到了一个嵌套的结束，需要把前面的数都进行处理掉
                if (!num.empty()) { // 首先把当前处理的数据放进来
                    st.top().add(NestedInteger(stoi(num)));
                    num.clear();
                }
                if (st.size() > 1) {    // 然后处理上一个，需要把当前的 NestedInteger 添加进上一个元素里，让栈里面只能保存一个 NestedInteger
                    auto number = st.top();
                    st.pop();
                    st.top().add(number);
                }
            } else {    // 拼接元素
                num += s[i];
            }
        }
        return st.top();
    }
};