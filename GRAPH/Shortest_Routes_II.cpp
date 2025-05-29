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
    ll n, m,q;
    cin >>n>>m>>q;
    unordered_map<ll,vector<pair<ll,ll>>>adj;vector<vector<ll>>dist(n+1,vector<ll>(n+1,1e18));
    ll u,v,de;
    fri(m){
        cin>>u>>v>>de;
        adj[u].push_back({v,de});
        dist[u][v] = min(dist[u][v], de);
        dist[v][u] = min(dist[v][u], de);
    }
    fri(n+1)dist[i][i]=0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    while(q--){
        cin>>u>>v;
        if(dist[u][v]==1e18)cout<<-1<<'\n';
        else cout<<dist[u][v]<<'\n';
    }

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}