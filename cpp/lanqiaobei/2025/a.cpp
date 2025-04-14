/*
 * @Description: 
 * @Author: 天涯过客
 * @Date: 2025-04-12 17:33:29
 */
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int na,nb,nc;
    while(k--) {
        na = (b+c)/2;
        nb = (a+c)/2;
        nc = (a+b)/2;

        a = na;
        b = nb;
        c = nc;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}