from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        length = len(nums)
        if not nums or length < 3:
            return 0

        result = float('inf')
        nums.sort()

        for i in range(length):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left = i + 1
            right = length - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if s == target:
                    return s
                if abs(result - target) > abs(s - target):
                    result = s
                if s > target:
                    right -= 1
                if s < target:
                    left += 1
        return result


s = Solution()
print(s.threeSumClosest([-1, 2, 1, -4], 1))
