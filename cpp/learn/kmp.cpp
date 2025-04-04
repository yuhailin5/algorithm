/*
 * @Description: kmp算法
 * @Author: 天涯过客
 * @Date: 2025-03-25 20:06:45
 */
#include<bits/stdc++.h>
using namespace std;

void getNext(string s,vector<int>& next) {
    int n = s.size();
    int i = 1;
    int j = 0;
    next[0] = j;
    while(i<n) {
        while(j>0&&s[i]!=s[j]) {
            j = next[j-1];//回退到上一个字符的最长公共前后缀的next值
        }
        if(s[i]==s[j]) {
            j++;
        }
        next[i] = j;
        i++;
    }
}
void getNextval(vector<int> next,string pattern,vector<int>& nextval) {
    int n = pattern.size();
    
    for(int i = 0;i<n;i++) {
        if(pattern[i]!=pattern[next[i]]) {
            nextval[i] = next[i];
        } else {
            nextval[i] = next[next[i]];
        }
    }
}

int match(string text,string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> next(m,0);
    vector<int> nextval(m,0);
    getNext(pattern,next);
    getNextval(next,pattern,nextval);
    int j = 0;
    for (int i = 0;i<n;i++) {
        while(j>0&&text[i]!=pattern[j]) {
            j = nextval[j-1];
        }
        if(text[i]==pattern[j]) {
            j++;
        }
        if (j == m) {
            return i-m+1;
        }
    }
    return -1;
}


int main() {

    string text = "afeddcsbcsbaddscsbcsbcsbc";
    string pattern = "csbcsbc";
    cout<<match(text,pattern)<<endl;
    return 0;
}