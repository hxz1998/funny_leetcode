/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> mapper;
    int capacity;
public:
    Solution(int _capacity) : capacity(_capacity) {

    }

    int get(int key) {
        if (mapper.find(key) == mapper.end()) return -1;
        auto iter = mapper[key];
        pair<int, int> node = {iter->first, iter->second};
        data.erase(iter);
        data.push_front(node);
        mapper[key] = data.begin();
        return node.second;
    }

    void set(int key, int value) {
        if (mapper.find(key) != mapper.end()) {
            auto iter = mapper[key];
            pair<int, int> node = {iter->first, value};
            data.erase(iter);
            data.push_front(node);
            mapper[key] = data.begin();
        } else {
            if (mapper.size() >= capacity) {
                pair<int, int> node = data.back();
                mapper.erase(node.first);
                data.pop_back();
                data.push_front({key, value});
            } else {
                data.push_front({key, value});
            }
            mapper[key] = data.begin();
        }
    }
};

int main() {
    Solution s(2);
    s.set(1, 1);
    s.set(2, 2);
    cout << s.get(1) << endl;
    s.set(3, 3);
    cout << s.get(2) << endl;
}