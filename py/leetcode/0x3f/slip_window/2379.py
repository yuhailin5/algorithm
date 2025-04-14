from math import inf

class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        l = 0
        r = 0
        cnt = 0
        ans = inf
        while r < n:
            if blocks[r] == 'W':
                cnt += 1
            r += 1
            if r - l == k:
                ans = min(ans,cnt)
                if blocks[l] == 'W':
                    cnt -= 1
                l += 1
        return ans
