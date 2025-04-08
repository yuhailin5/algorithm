class Solution:
    def isyunyin(self,c) -> bool:
        return not (c not in 'aeiou')
    
    def maxVowels(self, s: str, k: int) -> int:
        q = []
        cnt = 0
        max = 0
        for _ , c in enumerate(s):
            if len(q) >= k:
                if self.isyunyin(q.pop(0)): #python数组指定位置删除pop 或者remove
                    cnt -= 1
            q.append(c)
            if self.isyunyin(c):
                cnt += 1
                max = max if max > cnt else cnt
        return max
        