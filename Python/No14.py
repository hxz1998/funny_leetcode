from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        lengths = []
        strs_length = len(strs)
        for i in range(strs_length):
            lengths.append(len(strs[i]))
        min_length = min(lengths)
        result = ""
        for i in range(min_length):
            c = strs[0][i]
            for j in range(1, strs_length):
                if strs[j][i] is not c:
                    return result

            result += c
        return result


s = Solution()
print(s.longestCommonPrefix(["flower", "flow", "flight"]))
