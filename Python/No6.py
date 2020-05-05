class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [""] * min(numRows, len(s))

        curRow = 0
        goingDown = False

        for c in s:
            rows[curRow] += c
            if curRow == 0 or curRow == numRows - 1:
                goingDown = not goingDown
            curRow += 1 if goingDown else -1

        result = ""
        for item in rows:
            result += item
        return result


s = Solution()
print(s.convert("PAYPALISHIRING", 3))

# 可以得到系统下的最大数值表示
# import sys
# print(sys.maxsize)
