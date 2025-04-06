#include<bits/stdc++.h>
using namespace std;

int lowbit(int x) {
    return x&(-x);
}

class TreeArr {
public:
    TreeArr(int size) : n(size),tree(size+1,0) {}

    //树状数组中 每个节点的父节点为x+lowbit(x) 所以更新时所有父节点都需要更新
    void update(int idx,int val) {
        for(int i = idx;i<=n;i+=lowbit(i)) {
            tree[i] += val;
        }
    }

    //所以查询时就只需要减去lowbit就是前缀和
    int query(int idx) {
        int sum = 0;
        for(int i = idx;i>0;i-=lowbit(i)) {
            sum += tree[i];
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }

    void display() {
        for(int x:tree) {
            cout<<x<<" ";
        }
    }
private:
    vector<int> tree;
    int n;
};


void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i = 0;i<n;i++) {
        cin>>nums[i];
    }

    //初始化树状数组
    TreeArr tree(n);
    for(int i = 0;i<n;i++) {
        tree.update(i+1,nums[i]);
    }

    int op,x,y;
    while(m--) {
        cin>>op>>x>>y;
        if(op==1) {
            tree.update(x,y);
        }else {
            cout<<tree.rangeQuery(x,y)<<endl;
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