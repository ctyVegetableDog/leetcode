# 数组中字符串的最大值

'''
一个由字母和数字组成的字符串的 值 定义如下：

如果字符串 只 包含数字，那么值为该字符串在 10 进制下的所表示的数字。
否则，值为字符串的 长度 。
给你一个字符串数组 strs ，每个字符串都只由字母和数字组成，请你返回 strs 中字符串的 最大值 。
'''

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max([int(each) if each.isdecimal() else len(each) for each in strs])
