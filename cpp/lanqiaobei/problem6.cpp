#include<bits/stdc++.h>

using namespace std;
vector<vector<bool>> visited;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<int> ndfs;
vector<int> wdfs;
vector<int> path;
vector<int> res;

bool check(vector<int> north,vector<int> west) {
    for(int i = 0;i<north.size();i++) {
        if(ndfs[i]!=north[i]) {
            return false;
        }
    }
    for(int i = 0;i<west.size();i++) {
        if(wdfs[i]!=west[i]) {
            return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>> matrix,int x,int y,vector<int> north,vector<int> west) {
    if (res.size() > 0) return; // 如果已经找到路径，终止搜索

    if(x==matrix.size() - 1&&y==matrix[0].size() - 1) {
        // 对比把数
        if(check(north,west)) {
            // 成功 记录路径返回
            for (int i = 0; i < path.size(); i++) {
                res.push_back(path[i]);
            }
            return;
        }
    }
    for(int i = 0;i<4;i++) {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=0&&nx<matrix.size()&&ny>=0&&ny<matrix[0].size()&&!visited[nx][ny]
            &&ndfs[ny]+1<=north[ny]&&wdfs[nx]+1<=west[nx]) {
            // 先处理射箭的情况北边和西边
            ndfs[ny]++;
            wdfs[nx]++;
            visited[nx][ny] = true;
            // 加入路径
            path.push_back(matrix[nx][ny]);
            dfs(matrix,nx,ny,north,west);
            // 撤回路径
            path.pop_back();
            visited[nx][ny] = false;
            ndfs[ny]--;
            wdfs[nx]--;
        }
    }
}

int main() {
    int n;
    cin>>n;
    ndfs.resize(n,0);
    wdfs.resize(n,0);
    vector<vector<int>> matrix(n,vector<int>(n));
    visited.resize(n,vector<bool>(n,false));
    vector<int> north(n);
    vector<int> west(n);
    for(int i = 0;i<n;i++) {
        cin>>north[i];
    }
    for(int i = 0;i<n;i++) {
        cin>>west[i];
    }
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            matrix[i][j] = cnt++;
        }
    }
    visited[0][0] = true;
    path.push_back(matrix[0][0]);
    ndfs[0]++;
    wdfs[0]++;
    dfs(matrix,0,0,north,west);
    for(int i = 0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }

    return 0;
}