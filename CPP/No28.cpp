#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++) // 记住需要折半查找，否则时间会溢出
        {
            int current_i = i, j = 0;
            while (haystack[current_i] == needle[j] && j < needle.size() && current_i < haystack.size())
            {
                current_i++;
                j++;
            }
            if (j == needle.size())
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char *args[])
{
    string haystack = "mississippi";
    string needle = "mississippi";

    Solution s;
    printf("%d\n", s.strStr(haystack, needle));
}