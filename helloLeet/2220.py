# 转换数字的最少位翻转次数

class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        return len([i for i in bin(start ^ goal) if i == '1'])
