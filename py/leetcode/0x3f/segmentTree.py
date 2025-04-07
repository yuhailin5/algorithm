'''
Description: leetcode线段树模板
Author: 天涯过客
Date: 2025-04-07 20:07:53
'''
class NumArray:

    def __init__(self, nums):
        self.n = len(nums)
        self.sum = [0]*(2<<self.n.bit_length())
        self.build(1,0,self.n-1,nums)

    def build(self,o:int,l:int,r:int,nums):
        if l == r:
            if l < len(nums):
                self.sum[o] = nums[l]
            return
        
        mid = (l+r)//2
        self.build(o*2,l,mid,nums)
        self.build(o*2+1,mid+1,r,nums)
        self.sum[o] = self.sum[o*2]+self.sum[o*2+1]


    def update(self, index: int, val: int) -> None:
        def do_update(o:int,l:int,r:int) -> None:
            if l == r:
                self.sum[o] = val
                return
            
            mid = (l+r)//2
            if index <= mid:
                do_update(o*2,l,mid)
            else:
                do_update(o*2+1,mid+1,r)
            self.sum[o] = self.sum[o*2]+self.sum[o*2+1]
        do_update(1,0,self.n-1)
        

    def sumRange(self, left: int, right: int) -> int:
        def do_sum(o:int,l:int,r:int) -> int:
            if l > right or left > r:
                return 0
            if left <= l and r <= right:
                return self.sum[o]
            
            mid = (l+r)//2
            return do_sum(o*2,l,mid)+do_sum(o*2+1,mid+1,r)
        return do_sum(1,0,self.n-1)        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)