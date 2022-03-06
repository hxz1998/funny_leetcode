/**
 * Created by Xiaozhong on 2022/3/5.
 * Copyright (c) 2022/3/5 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"

using namespace std;

int main() {
    int src = 0;
    const int *num = &src;
    int *copy = const_cast<int *>(num);
    int *nc = &src;
    (*copy)++;
    double ds = 2.0;
    double *dp = &ds;
    long long *lp = reinterpret_cast<long long *>(dp);
    cout << ++(*lp) << endl;
    cout << *copy << endl;
    return 0;
}