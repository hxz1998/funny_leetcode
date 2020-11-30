/**
 * Created by Xiaozhong on 2020/11/30.
 * Copyright (c) 2020/11/30 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> counter(26, 0);
        for (const char &c : S) counter[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (counter[i] > (S.size() + 1) / 2) return "";
            if (counter[i] > 0) pq.push({counter[i], 'a' + i});
        }
        pair<int, char> prev(0, ' ');
        string buf;
        while (!pq.empty()) {
            pair<int, char> cur = pq.top();
            pq.pop();
            buf.push_back(cur.second);
            cur.first--;
            if (prev.first > 0) pq.push(prev);
            prev = cur;
        }
        return buf;
    }
};

int main() {
    Solution s;
    cout << s.reorganizeString("aaab") << endl;
    cout << s.reorganizeString("aab") << endl;
    cout << s.reorganizeString("vvvlo") << endl;
}