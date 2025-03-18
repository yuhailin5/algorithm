/*
 * @Description: 蓝桥杯第五题
 * @Author: 天涯过客
 * @Date: 2025-03-13 09:14:17
 */
#include<bits/stdc++.h>
using namespace std;
const int MOD = 10000;
int memo[1001][1001] = {0};


/**
 * @brief dfs记忆化搜索
 * 其实使用两个参数即可
 * @param n 前一个数
 * @param t 后一个数
 * @param max 这个数的最大值
 * @return int 组合数
 */
int dfs(int n,int t) {
    return t<=0?0:memo[n][t]?memo[n][t]:memo[n][t] = (dfs(n,t-1)+dfs(t,abs(n-t)-1)+1)%MOD;
}



int main() {
    int n;
    cin>>n;
    cout<<dfs(n,n)<<endl;

    return 0;
}