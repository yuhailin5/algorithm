/*
 * @Description: 卡码网58题 区间和
 * @Author: 天涯过客
 * @Date: 2025-01-20 23:34:37
 */


#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> p(n+1);
    p[0] = 0;
    for(int i = 0;i<n;i++) {
        cin>>nums[i];
        p[i+1] = p[i] + nums[i];
    }
    
    
    int a,b;
    
    while(cin>>a>>b) {
        cout<<p[b+1]-p[a]<<endl;
    }
    return 0;
}