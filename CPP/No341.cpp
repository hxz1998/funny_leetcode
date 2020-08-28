/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "stack"

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> stk;

    // 将数据填充到栈里面
    void fill(const vector<NestedInteger> &nestedList) {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
            stk.push(*iter);
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        fill(nestedList);
    }

    int next() {
        // 从头部取出数据，然后返回
        NestedInteger integer = stk.top();
        stk.pop();
        return integer.getInteger();
    }

    bool hasNext() {
        // 判断栈顶是否是有效数字，如果是一个列表的话，那就将数据取出来，然后填充进去
        while (!stk.empty()) {
            auto cur = stk.top();
            if (cur.isInteger()) return true;
            stk.pop();
            fill(cur.getList());
        }
        // 如果没有符合要求的数据，那就返回 false 了
        return false;
    }
};