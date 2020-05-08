from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        mapper = ["", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        result = []

        def dfs(tmp, index):
            if index == len(digits):
                result.append(tmp)
                return

            c = digits[index]

            letters = mapper[ord(c) - 48]

            for i in letters:
                dfs(tmp + i, index + 1)

        dfs("", 0)
        return result


s = Solution()
print(s.letterCombinations("23"))
