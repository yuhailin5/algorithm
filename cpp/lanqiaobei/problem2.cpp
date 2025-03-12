/*
 * @Description: 单调栈
 * @Author: 天涯过客
 * @Date: 2025-03-11 13:18:08
 */
#include<bits/stdc++.h>
using namespace std;



void createMinIndex(vector<int> nums,vector<int> &left) {
    stack<int> st;
    left.resize(nums.size(),-1);
    st.push(0);
    for(int i = 0;i<nums.size();i++) {
        int cur = nums[i];
        while(!st.empty()&&cur<=nums[st.top()]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

void createMaxIndex(vector<int> nums,vector<int> &right) {
    stack<int> st;
    int n = nums.size();
    right.resize(n, -1);  // 默认-1（右侧无更大元素）

    for (int i = n - 1; i >= 0; i--) {
        // 维护递减栈：栈顶到栈底严格递减
        while (!st.empty() && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        // 栈不空时，栈顶即为右侧第一个更大元素的索引
        right[i] = st.empty() ? -1 : st.top();
        st.push(i);  // 压入当前索引供后续元素比较
    }
}



int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++) {
        cin>>nums[i];
    }

    vector<int> leftMin(n);//左小
    vector<int> rightMax(n);//右大
    createMinIndex(nums,leftMin);
    createMaxIndex(nums,rightMax);

    int cnt = 0;
    for(int i = 0;i<n;i++) {
        if(leftMin[i]!=-1&&rightMax[i]!=-1) {
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}