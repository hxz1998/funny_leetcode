class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s)
        if length == 0:
            return 0
        left = 0
        right = 0
        result = 0
        mark = [0] * 128

        for i in range(length):
            c = s[right]
            mark[ord(c)] += 1
            while mark[ord(c)] > 1:
                ch = s[left]
                mark[ord(ch)] -= 1
                left += 1
            result = max(right - left + 1, result)
            right += 1
        return result


s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
