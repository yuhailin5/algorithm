/*
 * @Description: 蓝桥杯第一题
 * @Author: 天涯过客
 * @Date: 2025-04-14 17:42:22
 */
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define mst(x,i) memset(x,i,sizeof(x))
#define gkd ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lb(x) (x&-x)
const int maxm=9+1e6;
const int N=9;
const int maxn=9+2e3;


void solve() {
    int x = 233, y = 666;
    // 计算圆的半径
    double r = sqrt(pow(x, 2) + pow(y, 2));
    // 计算圆心角（弧度制）
    double theta = atan2(y, x);
    // 计算弧长
    double arcLength = r * theta;
    int ans = int(arcLength);
    ans += arcLength - ans >= 0.5?1:0;
    ans += r;
    cout<< ans << endl;
}

int main() {

   gkd;
   int t = 1;
   while(t--)
   {
      solve();
   }

   return 0;
}
