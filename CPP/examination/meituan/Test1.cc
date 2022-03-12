/**
 * Created by Xiaozhong on 2022/3/12.
 * Copyright (c) 2022/3/12 Xiaozhong. All rights reserved.
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
    int T;
    cin >> T;
    function<bool(const string &)> check = [](const string &name) {
        int n = static_cast<int>(name.size());
        bool digit = false;
        for (int idx = 0; idx < n; ++idx) {
            if (!isdigit(name[idx]) && !isupper(name[idx]) && !islower(name[idx])) return false;
            if (idx == 0 && !(isupper(name[idx]) || islower(name[idx]))) return false;
            if (isdigit(name[idx])) digit = true;
        }
        return digit;
    };
    while (T-- > 0) {
        string name;
        cin >> name;
        if (check(name)) cout << "Accept" << endl;
        else cout << "Wrong" << endl;
    }
    return 0;
}