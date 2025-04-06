#include<bits/stdc++.h>
using namespace std;



void getNext(string pattern,vector<int> &next) {
    int n = pattern.size();
    int j = 0;
    next[0] = j;
    for(int i = 1;i<n;i++) {
        while(j>0&&pattern[i]!=pattern[j]) {
            j = next[j-1];//回退类似动态规划 找到最长的公共前后缀
        }
        if(pattern[i]==pattern[j]) {
            j+=1;
        }
        next[i] = j;
    }
}


void solve() {
    string text,pattern;
    cin>>text>>pattern;
    int n = pattern.size();
    vector<int> next(n,0);
    getNext(pattern,next);
    int j = 0;
    for(int i = 0;i<text.size();i++) {
        while(j>0&&text[i]!=pattern[j]) {
            j = next[j-1];
        }
        if(text[i]==pattern[j]) {
            j++;
        }
        if (j == n) {
            cout<<i-n+1<<endl;
            j = next[j-1];
        }
    }
    for(int x:next) {
        cout<<x<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}