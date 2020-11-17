/**
 * Created by Xiaozhong on 2020/11/15.
 * Copyright (c) 2020/11/15 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class OrderedStream {
    vector<string> data;
    int sz, ptr;
public:
    OrderedStream(int n) : sz(n), ptr(1) {
        data.resize(sz + 1);
    }

    vector<string> insert(int id, string value) {
        vector<string> ret;
        if (ptr == id) {
            data[ptr] = value;
            while (ptr <= sz && data[ptr] != "") {
                ret.emplace_back(data[ptr++]);
            }
        } else {
            data[id] = value;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

int main() {
    OrderedStream os(5);
    vector<string> ans = os.insert(3, "ccc");
    ans = os.insert(1, "aaa");
    ans = os.insert(2, "bbb");
    ans = os.insert(5, "eee");
    ans = os.insert(4, "ddd");
    return 0;
}