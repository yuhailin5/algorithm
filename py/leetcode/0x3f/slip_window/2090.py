'''
Description: leetcode 2090题
Author: 天涯过客
Date: 2025-04-08 21:41:30
'''
from types import List
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        avg = [-1]*n
        l = 0
        r = 0
        sum = 0
        while r < n:
            sum += nums[r]
            r += 1
            if r - l >= 2 * k + 1:
                avg[r-k-1] = sum//(2*k+1)
                sum -= nums[l]
                l += 1

        return avg