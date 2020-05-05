//
// Created by Monkey on 2020/5/5.
//

#include "iostream"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x, result = 0;
        while (temp != 0) {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        if (result == x) {
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome(121) << endl;
}