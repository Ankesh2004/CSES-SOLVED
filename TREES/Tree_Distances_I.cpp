#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
#define printv(v, start_idx)                   \
    for (int i = start_idx; i < v.size(); i++) \
        cout << v[i] << " ";

ll mod = 1e9 + 7;
ll MAXN=1e6;

void dfs(ll node, ll parent, unordered_map<ll,vector<ll>>&adj, ll&mx, ll&s, ll curr){
    if(curr > mx){
        mx = curr;
        s = node;
    }
    for(auto it : adj[node]){
        if(it != parent){
            dfs(it, node, adj, mx, s, curr + 1);
        }
    }
}
void dfs2(ll node, ll parent, unordered_map<ll,vector<ll>>&adj, ll curr,vector<ll>&dist){
    dist[node]=max(dist[node],curr);
    for(auto it : adj[node]){
        if(it != parent){
            dfs2(it, node, adj, curr + 1,dist);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    unordered_map<ll,vector<ll>>adj;
    ll u,v;
    fri(n-1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll mx=0,s=1;
    dfs(1, -1, adj, mx, s, 0);
    
    mx=0;
    ll s2;
    dfs(s,-1,adj,mx,s2,0);
    
    vector<ll>dist(n+1,0);
    // cout<<s<<" "<<s2<<'\n';
    dfs2(s,-1,adj,0,dist);
    dfs2(s2,-1,adj,0,dist);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // fri(t)
        solve();

    return 0;
}
