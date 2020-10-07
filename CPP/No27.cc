#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main(int argc, char *args[])
{
    Solution s;
    vector<int> nums = {3, 3};
    int ans = s.removeElement(nums, 3);
    for (int i = 0; i < ans; i++)
    {
        printf("%d - ", nums[i]);
    }
}