/**
 * Created by Xiaozhong on 2022/4/15.
 * Copyright (c) 2022/4/15 Xiaozhong. All rights reserved.
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

int main() {
    vector<vector<char>> board{
            {},
            {},
            {'A', 'B', 'C'},
            {'D', 'E', 'F'},
            {'G', 'H', 'I'},
            {'J', 'K', 'L'},
            {'M', 'N', 'O'},
            {'P', 'Q', 'R', 'S'},
            {'T', 'U', 'V'},
            {'W', 'X', 'Y', 'Z'}
    };

    string input;
    cin >> input;
    string buffer;
    int ptr = 0;
    char curr = '-';
    int prev = -1;
    for (int idx = 0; idx < static_cast<int>(input.size()); ++idx) {
        const char &c = input[idx];
        if (c < '1' || c > '9') continue;
        if (c == '1' && curr == '-') continue;
        if (c == '1' && curr != '-') {
            buffer.push_back(curr);
            curr = '-';
            ptr = 0;
            prev = 1;
        } else {
            int num = c - '0';
            if (num == prev) {
                ptr = (ptr + 1) % static_cast<int>(board[num].size());
                curr = board[num][ptr];
            } else {
                if (curr != '-') {
                    buffer.push_back(curr);
                    prev = num;
                    ptr = 0;
                    curr = board[num][ptr];
                } else {
                    curr = board[num][ptr];
                    prev = num;
                }
            }
        }
    }
    cout << buffer << endl;
}








