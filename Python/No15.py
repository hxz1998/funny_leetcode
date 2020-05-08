from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        if not nums or length < 3:
            return []

        nums.sort()
        result = []
        for i in range(length):
            if nums[i] > 0:
                return result
            if i > 0 and nums[i] == nums[i - 1]:  # 防止重复解
                continue
            left, right = i + 1, length - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] == 0:
                    result.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                else:
                    left += 1
        return result
