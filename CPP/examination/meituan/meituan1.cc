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

/*
int main() {
    int n = 0;
    while (cin >> n) {
        cout << n << endl;
    }
    cout << 0 << endl;
    return 0;
    */
/*vector<int> nums(n);
    for (int idx = 0; idx < n; ++idx) cin >> nums[idx];
    return 0;*//*

}*/

/*
int main() {
    int a, b;
    vector<int> res;
    while (cin >> a >> b) {
        res.push_back(a + b);
    }
}*/

/*
int main() {
    char ch = getchar();
    while (ch) {
        cout << ch;
        if (ch == '\0') return 0;
        ch = getchar();
    }
    return 0;
}*/

ostream &operator<<(ostream &os, const vector<int> &nums) {
    for (int num: nums) os << num << " ";
    return os;
}

vector<string> split(const string &str) {
    const char delimiter = ' ';
    vector<string> res;
    string buffer = "";
    for (char c: str) {
        if (c != delimiter) buffer.push_back(c);
        else {
            res.push_back(buffer);
            buffer = "";
        }
    }
    res.push_back(buffer);
    return res;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.length() == 0) break;
        int n = stoi(s);
        vector<int> nums(n);


        getline(cin, s);
        vector<string> ret = split(s);
        for (int idx = 0; idx < n; ++idx) nums[idx] = stoi(ret[idx]);
        cout << nums << endl;
    }
}
