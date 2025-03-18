


from functools import cache

@cache
def dfs(n,t,max):
    if max < 1:
        return 1
    ans = 1
    for i in range(1,max):
        ans += dfs(t,i,abs(t-i))
    return ans


n = int(input())
ans = 0

for i in range(1,n+1):
    ans += dfs(n,i,abs(n-i))

print(ans)