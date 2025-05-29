#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld long double
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";
 
const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 6;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>>v(n,vector<char>(m));
    vector<vector<char>>dir(n,vector<char>(m,'#'));
    vector<vector<bool>>vis(n,vector<bool>(m));
    ll sx,sy,ex,ey;
    fri(n){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                sx=i;
                sy=j;
            }
            if(v[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    queue<pair<ll,ll>>q;
    q.push({sx,sy});

    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();

        if(x==ex && y==ey){
            break;
        }

        fri(4){
            ll nx=x+dx[i],ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || v[nx][ny]=='#')continue;

            if(dx[i]==1){
                dir[nx][ny]='D';
            }
            else if(dx[i]==-1){
                dir[nx][ny]='U';
            }
            else if(dy[i]==1){
                dir[nx][ny]='R';
            }
            else{
                dir[nx][ny]='L';
            }
            vis[nx][ny]=true;
            q.push({nx,ny});
        }
    }
    if(dir[ex][ey]=='#'){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        string path="";
        ll x=ex,y=ey;
        
        while(x!=sx || y!=sy){
            path+=dir[x][y];
            if(dir[x][y]=='D'){
                x--;
            }
            else if(dir[x][y]=='U'){
                x++;
            }
            else if(dir[x][y]=='L'){
                y++;
            }
            else{
                y--;
            }
        }
        cout<<path.size()<<'\n';
        reverse(path.begin(),path.end());
        cout<<path<<'\n';
    }


}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}