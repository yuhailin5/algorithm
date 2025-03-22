'''
Description: 
Author: 天涯过客
Date: 2025-03-13 09:33:33
'''


nums = [5,3,1,45,6,12,5]


max = nums[0]
for i in range(1, len(nums)):
    print('cur:',nums[i])
    print('max:',max)
    if nums[i] > max:
        max = nums[i]
print(max)