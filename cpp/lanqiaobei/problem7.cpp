/*
 * @Description: 蓝桥杯并查集
 * @Author: 天涯过客
 * @Date: 2025-04-03 20:01:31
 */
#include<bits/stdc++.h>
using namespace std;

#define yes cout<<"Y"<<endl
#define no cout<<"N"<<endl

int father[100001];

void init(int n) {
    for (int i = 1;i<=n;i++) {
        father[i] = i;//每个元素指向自己
    }
}

//查找元素
int find(int u) {
    //路径压缩了 这里防止更多的路径 每个元素到终点只需要一个路劲
    return father[u]==u?u:father[u] = find(father[u]);
}


//是否相同
bool isSame(int u,int v) {
    u = find(u);
    v = find(v);

    return u == v;
}

void join(int u,int v) {
    //将两个链接
    u = find(u);
    v = find(v);

    if (u==v) {
        return;
    }
    father[v] = u;
}


int main() {
    int n,m;
    cin>>n>>m;
    init(n);
    int z,x,y;
    while(m--) {
        cin>>z>>x>>y;
        if(z==1) {
            join(x,y);
        }else {
            if(isSame(x,y)) {
                yes;
            }else {
                no;
            }
        }
    }
    return 0;
}