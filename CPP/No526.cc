/**
 * Created by Xiaozhong on 2020/10/12.
 * Copyright (c) 2020/10/12 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;

    void calculate(int N, int pos, vector<bool> &visited) {
        if (pos > N) ++count;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }

public:
    int countArrangement(int N) {
        vector<bool> visited(N + 1);
        calculate(N, 1, visited);
        return count;
    }
};