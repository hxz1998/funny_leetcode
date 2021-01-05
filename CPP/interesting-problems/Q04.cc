/**
 * Created by Xiaozhong on 2020/12/24.
 * Copyright (c) 2020/12/24 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

void cutbar(int m, int n) {
    int count = 0;
    int current = 1;
    while (current < n) {
        ++count;
        current += current < m ? current : m;
    }
    cout << count << endl;
}

int main() {
    cutbar(3, 20);
    cutbar(5, 100);
}