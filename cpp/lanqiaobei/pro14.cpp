/*
 * @Description: 贪心 数据规模10^4次
 * @Author: 天涯过客
 * @Date: 2025-04-07 12:49:55
 */
#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i = 1;i<=n;i++){
        cin>>nums[i];
    }

    int ans = 0;
    for(int i = 1;i<=n;i++) {
        if(nums[i]!=i) {
            ans++;
            for(int j = 1;j<=n;j++) {
                if(nums[j]==i) {
                    swap(nums[j],nums[i]);
                }
            }
        }
    }
    cout<<ans;
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