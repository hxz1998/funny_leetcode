from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j, result = 0, len(height) - 1, 0
        while i < j:
            if height[i] < height[j]:
                result = max(result, height[i] * (j - i))
                i += 1
            else:
                result = max(result, height[j] * (j - i))
                j -= 1
        return result


# 暴力枚举，不可行
# class Solution:
#     def maxArea(self, height: List[int]) -> int:
#         length = len(height)
#         maxSize = 0
#         for left in range(length):
#             right = 0
#             for right in range(left + 1, length):
#                 if right >= length:
#                     break
#                 maxSize = max(min(height[left], height[right]) * (right - left), maxSize)
#
#         return maxSize


s = Solution()
