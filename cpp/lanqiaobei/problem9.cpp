/*
 * @Description: 单调栈
 * @Author: 天涯过客
 * @Date: 2025-04-04 20:32:06
 */
#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i = 1;i<=n;i++) {
        cin>>nums[i];
    }

    vector<int> res(n+1);
    stack<int> st;
    st.push(1);
    for (int i = 2;i<=n;i++) {
        if(nums[i]>nums[st.top()]) {
            while(!st.empty()&&nums[i]>nums[st.top()]) {
                res[st.top()] = i;
                st.pop();
            }
        }
        st.push(i);
    }
    while(!st.empty()) {
        res[st.top()] = 0;
        st.pop();
    }
    for (int i = 1;i<=n;i++) {
        cout<<res[i]<<" ";
    }
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}