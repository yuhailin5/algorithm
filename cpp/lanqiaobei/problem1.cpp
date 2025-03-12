/*
 * @Description: 
 * @Author: 天涯过客
 * @Date: 2025-03-11 13:11:32
 */
#include<bits/stdc++.h>
using namespace std;

bool isvaild(int n){
    bool ans = true;
    int pre = 10;
    while(n>0) {
      int cur = n%10;
      if(pre<cur) return false;
      pre = cur;
      n/=10;
    }
    return ans;
}
  int main()
  {
    int n = 0;
    cin>>n;
    int cnt = 0;
    for(int i = 1;i<=n;i++) {
      if(isvaild(i)) cnt++;
    }
    cout<<cnt<<endl;
  
    return 0;
  }