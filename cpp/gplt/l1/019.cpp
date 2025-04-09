#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,n;
    cin>>a>>b>>n;
    int begina = a;
    int beginb = b;
    int a1,a2,b1,b2;
    while(n--) {
        cin>>a1>>a2>>b1>>b2;
        if((a2==a1+b1&&b2==a1+b1)||(a2!=a1+b1&&b2!=a1+b1)) {
            continue;
        }
        if(a2==a1+b1) {
            a--;
            if(a<0) {
                cout<<"A"<<endl;
                cout<<beginb-b<<endl;
                break;
            }
        }
        if(b2==a1+b1) {
            b--;
            if(b<0) {
                cout<<"B"<<endl;
                cout<<begina-a<<endl;
                break;
            }
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