/**
 * Created by Xiaozhong on 2021/10/31.
 * Copyright (c) 2021/10/31 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> record(n);
    for (int i = 0; i < n; ++i) {
        cin >> record[i];
    }
    sort(record.begin(), record.end());
    cout << record[1];
}