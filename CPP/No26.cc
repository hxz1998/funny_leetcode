#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;        
    }
};

int main(int argc, char *args[])
{
    vector<int> nums = {1, 1, 2, 3};
    Solution s;
    int ans = s.removeDuplicates(nums);
    for (int i = 0; i < ans; i++) 
    {
        printf("%d - ", nums[i]);
    }
}