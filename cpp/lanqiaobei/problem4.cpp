/**
 * @file problem4.cpp
 * @author tianyaguoke.com
 * @brief 蓝桥杯练习4题
 * @version 0.1
 * @date 2025-03-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    vector<vector<int>> visited(m,vector<int>(n,-1));//记录长草的时间
    queue<pair<int,int>> q;
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='g') {
                q.push(pair<int,int>{i,j});
                visited[i][j] = 0;
            }
        }
    }
    int k = 0;
    cin>>k;


    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0;i<4;i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx<0||nextx>=m||nexty<0||nexty>=n||visited[nextx][nexty]!=-1||grid[nextx][nexty]=='g') {
                continue;
            }
            visited[nextx][nexty] = visited[x][y] + 1;
            if(visited[nextx][nexty]<=k) {
                grid[nextx][nexty] = 'g';
                q.push(pair<int,int>{nextx,nexty});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}