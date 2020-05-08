from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        length = len(nums)
        if length < 4: return []

        nums.sort()
        result = []
        for i in range(length - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
                break
            if nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target:
                continue
            for j in range(i + 1, length - 2):
                if j - i > 1 and nums[j] == nums[j - 1]:
                    continue
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:
                    break
                if nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target:
                    continue
                left = j + 1
                right = length - 1
                while left < right:
                    sum_num = nums[i] + nums[j] + nums[left] + nums[right]
                    if sum_num == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif sum_num > target:
                        right -= 1
                    elif sum_num < target:
                        left += 1
        return result


s = Solution()
print(s.fourSum([1, 0, -1, 0, -2, 2], 0))
