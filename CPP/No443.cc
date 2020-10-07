/**
 * Created by Xiaozhong on 2020/9/22.
 * Copyright (c) 2020/9/22 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.size(); ++read) {
            if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
                chars[write++] = chars[anchor];
                if (read > anchor) {
                    for (char c : to_string(read - anchor + 1)) chars[write++] = c;
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};
