/*
 * @Description: 
 * @Author: 天涯过客
 * @Date: 2025-04-12 17:38:09
 */
#include<bits/stdc++.h>
using namespace std;
int a[100001] = {0};
int main() {
    int n;
    cin>>n;
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        int l = (a[i]/2) +1;
        int r = (a[i]/2) +1;
        long long sum = 0;
        while(l>-2) {
            sum += l;
            l--;
            if(sum==a[i]&&r-l>=3) {
                cnt++;
                break;
            }
            if(sum>a[i]) {
                sum-=r;
                r--;
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}