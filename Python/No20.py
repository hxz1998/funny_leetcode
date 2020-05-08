class Solution:
    def isValid(self, s: str) -> bool:
        if not s: return True
        if len(s) % 2 == 1: return False
        stack = []
        table = {')': '(', '}': '{', ']': '['}
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(c)
            elif c in [')', '}', ']']:
                if len(stack) != 0:
                    top = stack.pop()
                    if table[c] != top:
                        return False
                else:
                    return False
        if len(stack) != 0:
            return False
        return True


s = Solution()
print(s.isValid("()[{}]"))
