/*
 * @Description: 树状数组 差分 有问题
 * @Author: 天涯过客
 * @Date: 2025-04-06 19:11:49
 */
#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))

class TreeArr {
public:
    TreeArr(int size):n(size),tree(n+1,0) {}
    void update(int idx,int val) {
        for(int i = idx;i<=n;i+=lowbit(i)) {
            tree[i] += val;
        }
    }
    int query(int idx) {
        int sum = 0;
        for(int i = idx;i>0;i-=lowbit(i)) {
            sum += tree[i];
        }
        return sum;
    }
    int queryRange(int left,int right) {
        return query(right)-query(left-1);
    }

    void display() {
        cout<<"close!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        for(int x:tree) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

private:
    vector<int> tree;
    int n;
};



void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n+1);
    vector<int> d(n+1,0);
    TreeArr tree(n);
    nums[0] = 0;
    for(int i = 1;i<=n;i++) {
        cin>>nums[i];
        d[i] = nums[i]-nums[i-1];//差分数组
        tree.update(i,d[i]);
    }

    int op,x,y,k;
    while(m--) {
        cin>>op;
        if(op==1) {
            cin>>x>>y>>k;
            tree.update(x,k);
            cout<<"Before: ";
            tree.display();
            tree.update(y+1,-k);
            cout<<"After: ";
            tree.display();
        }else {
            cin>>x;
            cout<<tree.query(x)<<endl;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}