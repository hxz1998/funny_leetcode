#include <iostream>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int symbol = 0;
        if (dividend == 0)
            return 0;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            symbol = 1;
        else 
            symbol = -1;
        int i = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor)
        {
            dividend -= divisor;
            i++;
        }
        i *= symbol;
        return i;
    }
};

int main(int argc, char *args[])
{
    Solution s;
    printf("%d\n", s.divide(10, 3));
}