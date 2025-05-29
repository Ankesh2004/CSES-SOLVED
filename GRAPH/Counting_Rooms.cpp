#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
void bfs(int n,int m,vector<vector<bool>>&vis,vector<vector<char>>&grid,int sx,int sy){
    
    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
 
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
 
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='.'){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,m;cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }   
    }
 
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int cnt=0;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='.'){
                bfs(n,m,vis,grid,i,j);
                cnt++;
            }
        }   
    }
    cout<<cnt<<endl;
 
    
    return 0;
}