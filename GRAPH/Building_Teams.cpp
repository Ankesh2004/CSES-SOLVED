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

bool bfs(ll node,unordered_map<ll,vector<ll>>&adj,vector<ll>&color){
    queue<pair<ll,ll>>q;
    q.push({node,0});
    color[node]=0;

    while(!q.empty()){
        ll x=q.front().first,c=q.front().second;
        q.pop();

        for(auto it:adj[x]){
            
            if(color[it]==-1){
                color[it]=(c^1);
                q.push({it,c^1});
            }
            else if(color[it]==c){
                return false;
            }
        }
    }
    return true;
}
 
void solve()
{
    ll n, m;
    cin >>n>>m;
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(m){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>color(n+1,-1);
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            
            ans=bfs(i,adj,color);
            if(!ans){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]+1<<' ';
    }

}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    return 0;
}