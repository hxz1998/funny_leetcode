class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s
        first_match = bool(s) and p[0] in {s[0], '.'}

        if len(p) >= 2 and p[1] == '*':
            return (self.isMatch(s, p[2:]) or first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])


s = Solution()
print(s.isMatch("aa", "a"))
# bool 运算可以将内容进行布尔运算，如果为空内容 ""/0/None/False/[]/{}/()，那么输出为False
# 拓展：如果 p="" 为空，那么 not p == True
# print(bool("ads"))
# print("a" in {"a", '.'})
print((True or False) and False)
