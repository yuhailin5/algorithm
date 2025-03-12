/*
 * @Description: 
 * @Author: 天涯过客
 * @Date: 2025-03-11 17:54:58
 */
#include<bits/stdc++.h>
using namespace std;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;


int main() {
    string s;
    cin>>s;
    //辅元辅元4段顺序不能变
    bool ans = true;
    int n = s.size();
    int word[26] = {0};
    memset(word,1,sizeof(word));
    word['a'-'a'] = 0;
    word['e'-'a'] = 0;
    word['i'-'a'] = 0;
    word['o'-'a'] = 0;
    word['u'-'a'] = 0;
    int cnt = 0;
    int pre = word[s[0]-'a'];
    for(int i = 1;i<n;i++) {
        if(pre==1&&word[s[i]-'a']) continue;
        if(pre==0&&word[s[i]-'a']==0) continue;
        cnt++;
        if(cnt==1) {
            if(pre!=1) {
                ans = false;
                break;
            }
        }else if(cnt==2) {
            if(pre!=0) {
                ans = false;
                break;
            }
        }else if(cnt==3) {
            if(pre!=1) {
                ans = false;
                break;
            }
        }else if(cnt==4) {
            if(pre!=0) {
                ans = false;
                break;
            }
        }
        pre = pre ? 0:1;
    }

    if(ans) yes
    else no

    return 0;
}