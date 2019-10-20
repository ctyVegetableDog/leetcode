#hash

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, each in enumerate(nums):
            dict[each] = i
        for i, each in enumerate(nums):
            j = dict.get(target - each)
            if (j != None and j != i):
                return (i,j)
