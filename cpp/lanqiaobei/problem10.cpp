/*
 * @Description: 快速幂
 * @Author: 天涯过客
 * @Date: 2025-04-04 23:50:39
 */
#include<bits/stdc++.h>
using namespace std;
// 2 的 10次
/**
 * 
 * @brief 10 1010二进制  
 * 
 * @param a 
 * @param b 
 * @param p 
 * @return int 
 */
int quick_pow(int a,int b,int p) {
    int ans = 1;
    while(b) {
        a %= p;
        if (b&1) {
            ans = ans * a % p;
        }
        b>>=1;
        a = a * a % p;
    }
    return ans;
}


void solve() {
    int a,b,p;
    cin>>a>>b>>p;
    int ans = quick_pow(a,b,p);
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
