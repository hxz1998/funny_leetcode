/**
 * Created by Xiaozhong on 2020/10/9.
 * Copyright (c) 2020/10/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <random>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> V;
    int rows, cols, remind;
public:

    //c++11 random integer generation
    mt19937 rng{random_device{}()};

    //uniform random integer in [0, bound]
    int randint(int bound) {
        uniform_int_distribution<int> uni(0, bound);
        return uni(rng);
    }

    Solution(int n_rows, int n_cols) {
        rows = n_rows, cols = n_cols, remind = rows * cols;
    }

    vector<int> flip() {
        int r = randint(--remind);
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(remind) ? V[remind] : V[remind] = remind;
        return {x / cols, x % cols};
    }

    void reset() {
        V.clear();
        remind = rows * cols;
    }
};