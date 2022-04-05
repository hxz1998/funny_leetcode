/**
 * Created by Xiaozhong on 2022/3/23.
 * Copyright (c) 2022/3/23 Xiaozhong. All rights reserved.
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

class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> mapper;
    default_random_engine e;
    uniform_int_distribution<int> engine;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (mapper.find(val) != mapper.end()) return false;
        mapper[val] = data.size();
        data.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (mapper.find(val) == mapper.end()) return false;
        int index = mapper[val];
        data[index] = data.back();
        if (index != data.size() - 1) {
            int backData = data.back();
            mapper[backData] = index;
        }
        data.pop_back();
        mapper.erase(val);
        return true;
    }

    int getRandom() {
        engine = uniform_int_distribution<int>(0, data.size() - 1);
        int randIndex = engine(e);
        return data[randIndex];
    }
};

int main() {
    RandomizedSet randomizedSet;
    randomizedSet.insert(0);
    randomizedSet.insert(1);
    randomizedSet.remove(0);
    randomizedSet.insert(2);
    randomizedSet.remove(1);
    cout << randomizedSet.getRandom() << endl;
}