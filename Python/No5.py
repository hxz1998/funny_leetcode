class Solution:

    def expand_around_center(self, s: str, left: int, right: int) -> int:
        L, R = left, right
        while L >= 0 and R < len(s) and s[L] == s[R]:
            L -= 1
            R += 1
        return R - L - 1

    def longestPalindrome(self, s: str) -> str:
        if s == None or len(s) < 1:
            return ""
        start, end = 0, 0
        for i in range(len(s)):
            len1 = self.expand_around_center(s, i, i)
            len2 = self.expand_around_center(s, i, i + 1)
            length = max(len1, len2)
            if length > end - start:
                start = i - int((length - 1) / 2)
                end = i + int(length / 2)
        return s[start:end + 1]


s = Solution()
print(s.longestPalindrome("babad"))
