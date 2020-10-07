//
// Created by Monkey on 2020/5/5.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0, temp = x;
        while (temp != 0) {
            int pop = temp % 10;
            temp /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            result = 10 * result + pop;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
}