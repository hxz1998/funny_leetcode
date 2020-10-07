/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */

#include "set"
#include "iostream"

using namespace std;

class Solution {
private:
    // 计算规则
    int getNext(int n) {
        int total_sum = 0;
        while (n > 0) {
            int t = n % 10;
            n /= 10;
            total_sum += t * t;
        }
        return total_sum;
    }

public:
    /*bool isHappy(int n) {
        set<int> s;
        while (n != 1 && !s.count(n)) {// 根据计算规则迭代计算
            s.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }*/
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
}