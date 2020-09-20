/**
 * Created by Xiaozhong on 2020/9/20.
 * Copyright (c) 2020/9/20 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
private:
    vector<string> split(string s) {
        vector<string> res;
        string buf = "";

        for (char c : s) {
            if (c != ' ') {
                buf.push_back(c);
            } else if (c == ' ' && buf.size() != 0) {
                res.push_back(buf);
                buf = "";
            }
        }
        return res;
    }

    string appendSpace(int n) {
        string s = "";
        for (int i = 0; i < n; ++i) s += " ";
        return s;
    }

public:
    string reorderSpaces(string text) {
        int space_count = 0, word_count = 0;
        string ans = "";
        for (char c : text) if (c == ' ') ++space_count;
        vector<string> words = split(text);
        word_count = words.size();
        int evr_space = space_count / (word_count - 1);
        int rem_space = space_count % (word_count - 1);
        string space = appendSpace(evr_space);
        for (int i = 0; i < words.size() - 1; ++i) {
            ans.append(words[i]).append(space);
        }
        ans.append(words.back());
        ans.append(appendSpace(rem_space));
        return ans;
    }

};

int main() {
    Solution s;
    cout << s.reorderSpaces("  this   is  a sentence ") << "---" << endl;
    cout << s.reorderSpaces(" practice   makes   perfect") << "---" << endl;
}