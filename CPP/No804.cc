/**
 * Created by Xiaozhong on 2020/12/7.
 * Copyright (c) 2020/12/7 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    // 字符映射表
    const vector<string> table = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                  "--",
                                  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                                  "--.."};
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        // 可以拼凑成的集合
        unordered_set<string> codes;
        // 对每一个单词进行翻译，并检测是否已有翻译结果在集合中
        for (const string &word : words) {
            string buf;
            for (char c : word) buf.append(table[c - 'a']);
            if (!codes.count(buf)) codes.insert(buf);
        }
        return codes.size();
    }
};

int main() {
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << s.uniqueMorseRepresentations(words) << endl;
}