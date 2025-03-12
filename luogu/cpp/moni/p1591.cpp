#include <bits/stdc++.h>

using namespace std;


vector<int> factorial(int n){
    vector<int> ans = {1};

    for (int i = 2; i <= n; ++i) {
        int carry=0;
        for (int j = 0; j < ans.size(); ++j) {
            int x=ans[j]*i+carry;
            ans[j]=x%10;
            carry=x/10;
        }
        while(carry) {
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    return ans;
}


int count(int n,int a) {
    vector<int> ans = factorial(n);

    auto getSum = [ans]() -> int  {
        int sum = 0;
        for (int i = 0; i < ans.size(); ++i) {
            sum+=ans[i];
        }
        return sum;
    };
    cout<<getSum()<<endl;
    int count=0;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i]==a) count++;
    }
    return count;
}

int main() {
    int t,n,a;
    cin>>t;
    while(t--) {
        cin>>n>>a;
        cout<<count(n,a)<<endl;
    }


    return 0;
}